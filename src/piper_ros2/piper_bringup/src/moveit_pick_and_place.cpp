#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>
#include <moveit/planning_scene_interface/planning_scene_interface.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <control_msgs/action/parallel_gripper_command.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <moveit_msgs/msg/robot_trajectory.hpp>
#include <moveit_msgs/msg/collision_object.hpp>
#include <shape_msgs/msg/solid_primitive.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <scene_graph_interfaces/msg/fun_object3_d_bounding_box_list.hpp>
#include <scene_graph_interfaces/msg/fun_object3_d_bounding_box.hpp>

using namespace std::chrono_literals;

enum class Affordance {
    GRASPABLE,
    PUSHABLE,
    PULLABLE,
    NONE
};

enum class GraspType {
    TOP_DOWN,
    SIDE,
    ANGLED
};

struct ObjectAffordance {
    Affordance primary;
    Affordance secondary;
};

struct ObjectGraspConfig {
    GraspType grasp_type;
    std::string description;
};

struct DetectedObject {
    std::string class_name;
    double x, y, z;
    double width, height, depth;
    Affordance affordance;
};

class PiperDynamicNode : public rclcpp::Node {
public:
    using GripperAction = control_msgs::action::ParallelGripperCommand;
    using BBoxList = scene_graph_interfaces::msg::FunObject3DBoundingBoxList;

    PiperDynamicNode() : Node("piper_dynamic_engine") {
        this->set_parameter(rclcpp::Parameter("use_sim_time", true));
        this->arm_pub_ = this->create_publisher<trajectory_msgs::msg::JointTrajectory>(
            "/joint_trajectory_controller/joint_trajectory", 10);
        this->gripper_client_ = rclcpp_action::create_client<GripperAction>(
            this, "/gripper_controller/gripper_cmd");
        this->obj_sub_ = this->create_subscription<BBoxList>(
            "/bounding_boxes_3d/rtdetr", 10,
            std::bind(&PiperDynamicNode::vision_callback, this, std::placeholders::_1));
        
        initialize_affordances();
        initialize_grasp_configs();
        RCLCPP_INFO(this->get_logger(), "Piper Ready with Smart Place!");
    }

    void run() {
        auto move_group = std::make_shared<moveit::planning_interface::MoveGroupInterface>(
            shared_from_this(), "manipulator");
        move_group->setPlanningTime(20.0);
        move_group->setMaxVelocityScalingFactor(0.15);
        move_group->setGoalPositionTolerance(0.005); 

        while (rclcpp::ok()) {
            if (action_received_) {
                RCLCPP_INFO(this->get_logger(), "");
                RCLCPP_INFO(this->get_logger(), "╔═══════════════════════════════════════════════╗");
                RCLCPP_INFO(this->get_logger(), "║  OBJECT: %-37s║", latest_target_.class_name.c_str());
                RCLCPP_INFO(this->get_logger(), "╚═══════════════════════════════════════════════╝");
                
                plan_and_execute_standard(*move_group, "home");
                
                if (latest_target_.affordance == Affordance::GRASPABLE) {
                    spawn_collision_object(latest_target_);
                    execute_intelligent_grasp(move_group, latest_target_);
                    move_group->attachObject("target_object");
                    
                    // Pass object info to place function
                    execute_intelligent_place(move_group, latest_place_, latest_target_);
                    
                    move_group->detachObject("target_object");
                    remove_object("target_object");
                } else if (latest_target_.affordance == Affordance::PUSHABLE) {
                    execute_push_action(move_group, latest_target_);
                } else if (latest_target_.affordance == Affordance::PULLABLE) {
                    execute_pull_action(move_group, latest_target_);
                }

                plan_and_execute_standard(*move_group, "home");
                action_received_ = false;
                RCLCPP_INFO(this->get_logger(), "✅ Complete!");
            }
            rclcpp::sleep_for(100ms);
        }
    }

private:
    void initialize_affordances() {
        affordance_map_["keyboard"] = {Affordance::GRASPABLE, Affordance::NONE};
        affordance_map_["mouse"] = {Affordance::GRASPABLE, Affordance::NONE};
        affordance_map_["trash can"] = {Affordance::GRASPABLE, Affordance::NONE};
        affordance_map_["book"] = {Affordance::GRASPABLE, Affordance::NONE};
        affordance_map_["vase"] = {Affordance::GRASPABLE, Affordance::NONE};
        affordance_map_["plant"] = {Affordance::GRASPABLE, Affordance::NONE};
        affordance_map_["clock"] = {Affordance::GRASPABLE, Affordance::NONE};
        affordance_map_["dish"] = {Affordance::GRASPABLE, Affordance::NONE};
        affordance_map_["cup"] = {Affordance::GRASPABLE, Affordance::NONE};
        affordance_map_["bottle"] = {Affordance::GRASPABLE, Affordance::NONE};
        affordance_map_["box"] = {Affordance::GRASPABLE, Affordance::NONE};
        affordance_map_["bag"] = {Affordance::GRASPABLE, Affordance::NONE};
        affordance_map_["shoe"] = {Affordance::GRASPABLE, Affordance::NONE};
        affordance_map_["backpack"] = {Affordance::GRASPABLE, Affordance::NONE};
        affordance_map_["cylinder"] = {Affordance::GRASPABLE, Affordance::NONE};
        affordance_map_["door"] = {Affordance::PUSHABLE, Affordance::PULLABLE};
        affordance_map_["drawer"] = {Affordance::PULLABLE, Affordance::PUSHABLE};
        affordance_map_["cabinet"] = {Affordance::PUSHABLE, Affordance::PULLABLE};
        affordance_map_["cupboard"] = {Affordance::PUSHABLE, Affordance::PULLABLE};
    }

    void initialize_grasp_configs() {
        grasp_config_map_["cylinder"] = {GraspType::SIDE, "Cylinder - SIDE"};
        grasp_config_map_["bottle"] = {GraspType::SIDE, "Bottle - SIDE"};
        grasp_config_map_["cup"] = {GraspType::SIDE, "Cup - SIDE"};
        grasp_config_map_["vase"] = {GraspType::SIDE, "Vase - SIDE"};
        grasp_config_map_["plant"] = {GraspType::SIDE, "Plant - SIDE"};
        grasp_config_map_["trash can"] = {GraspType::SIDE, "Trash can - SIDE"};
        grasp_config_map_["box"] = {GraspType::TOP_DOWN, "Box - TOP"};
        grasp_config_map_["cube"] = {GraspType::TOP_DOWN, "Cube - TOP"};
        grasp_config_map_["book"] = {GraspType::TOP_DOWN, "Book - TOP"};
        grasp_config_map_["keyboard"] = {GraspType::TOP_DOWN, "Keyboard - TOP"};
        grasp_config_map_["mouse"] = {GraspType::TOP_DOWN, "Mouse - TOP"};
        grasp_config_map_["dish"] = {GraspType::TOP_DOWN, "Dish - TOP"};
        grasp_config_map_["clock"] = {GraspType::TOP_DOWN, "Clock - TOP"};
        grasp_config_map_["shoe"] = {GraspType::TOP_DOWN, "Shoe - TOP"};
        grasp_config_map_["bag"] = {GraspType::TOP_DOWN, "Bag - TOP"};
        grasp_config_map_["backpack"] = {GraspType::TOP_DOWN, "Backpack - TOP"};
    }

    ObjectAffordance get_affordance(const std::string& class_name) {
        auto it = affordance_map_.find(class_name);
        if (it != affordance_map_.end()) return it->second;
        return {Affordance::NONE, Affordance::NONE};
    }

    GraspType get_grasp_type(const std::string& class_name, const DetectedObject& obj) {
        auto it = grasp_config_map_.find(class_name);
        if (it != grasp_config_map_.end()) {
            RCLCPP_INFO(this->get_logger(), "🎯 %s", it->second.description.c_str());
            return it->second.grasp_type;
        }
        
        double max_base = std::max(obj.width, obj.depth);
        double aspect_ratio = obj.height / max_base;
        
        if (aspect_ratio > 1.5) {
            RCLCPP_INFO(this->get_logger(), "🎯 Auto: SIDE (ratio=%.2f)", aspect_ratio);
            return GraspType::SIDE;
        } else {
            RCLCPP_INFO(this->get_logger(), "🎯 Auto: TOP (ratio=%.2f)", aspect_ratio);
            return GraspType::TOP_DOWN;
        }
    }

    std::string affordance_to_string(Affordance aff) {
        switch(aff) {
            case Affordance::GRASPABLE: return "GRASPABLE";
            case Affordance::PUSHABLE: return "PUSHABLE";
            case Affordance::PULLABLE: return "PULLABLE";
            default: return "NONE";
        }
    }

    void vision_callback(const BBoxList::SharedPtr msg) {
        if (msg->bbox.empty() || action_received_) return;

        for (const auto& obj : msg->bbox) {
            ObjectAffordance aff = get_affordance(obj.name.data);
            
            if (aff.primary != Affordance::NONE || obj.graspable) {
                latest_target_.class_name = obj.name.data;
                latest_target_.x = (obj.bounding_box[0].x + obj.bounding_box[1].x) / 2.0;
                latest_target_.y = (obj.bounding_box[0].y + obj.bounding_box[1].y) / 2.0;
                latest_target_.z = (obj.bounding_box[0].z + obj.bounding_box[1].z) / 2.0;
                latest_target_.width = std::abs(obj.bounding_box[1].x - obj.bounding_box[0].x);
                latest_target_.height = std::abs(obj.bounding_box[1].z - obj.bounding_box[0].z);
                latest_target_.depth = std::abs(obj.bounding_box[1].y - obj.bounding_box[0].y);
                
                if (obj.graspable || aff.primary == Affordance::GRASPABLE) {
                    latest_target_.affordance = Affordance::GRASPABLE;
                } else {
                    latest_target_.affordance = aff.primary;
                }
                
                latest_place_.class_name = obj.name.data;
                latest_place_.x = 0.2;
                latest_place_.y = 0.2;
                latest_place_.z = 1.1;  // Place location height
                latest_place_.width = 0;
                latest_place_.height = latest_target_.height;  // Keep object height
                latest_place_.depth = 0;
                latest_place_.affordance = Affordance::NONE;
                
                action_received_ = true;
                RCLCPP_INFO(this->get_logger(), "📍 Detected: %s (H=%.3f)", 
                           obj.name.data.c_str(), latest_target_.height);
            }
        }
    }

    void execute_intelligent_grasp(std::shared_ptr<moveit::planning_interface::MoveGroupInterface> group, 
                                   const DetectedObject& obj) {
        GraspType grasp_type = get_grasp_type(obj.class_name, obj);
        
        send_gripper_command(0.038);
        rclcpp::sleep_for(1500ms);

        if (grasp_type == GraspType::SIDE) {
            RCLCPP_WARN(this->get_logger(), "═══ SIDE GRASP (with dive) ═══");
            
            double object_bottom = obj.z - (obj.height / 2.0);
            double grasp_height = object_bottom + (obj.height * 0.5)+0.1;
            
            RCLCPP_INFO(this->get_logger(), "Target grasp height: Z=%.3f (middle)", grasp_height);
            
            double high_z = obj.z + 0.25;
            RCLCPP_INFO(this->get_logger(), "Step 1: High above [%.3f, %.3f, %.3f]", obj.x, obj.y, high_z);
            plan_and_execute_standard(*group, obj.x, obj.y, high_z);
            rclcpp::sleep_for(1s);
            
            RCLCPP_WARN(this->get_logger(), "Step 2: ⬇️  DIVING to middle Z=%.3f", grasp_height);
            perform_linear_move(*group, obj.x, obj.y, grasp_height);
            rclcpp::sleep_for(1s);
            
            RCLCPP_WARN(this->get_logger(), "Step 3: 🤏 GRASPING at middle...");
            send_gripper_command(0.0);
            rclcpp::sleep_for(2000ms);
            
            RCLCPP_INFO(this->get_logger(), "Step 4: ⬆️  Lifting to Z=%.3f", high_z);
            perform_linear_move(*group, obj.x, obj.y, high_z);
            
        } else {
            RCLCPP_INFO(this->get_logger(), "═══ TOP GRASP (with dive) ═══");
            
            double high_z = obj.z + 0.25;
            double grasp_z = obj.z;
            double lift_z = obj.z + 0.25;
            
            RCLCPP_INFO(this->get_logger(), "Step 1: Above [%.3f, %.3f, %.3f]", obj.x, obj.y, high_z);
            plan_and_execute_standard(*group, obj.x, obj.y, high_z);
            rclcpp::sleep_for(1s);
            
            RCLCPP_WARN(this->get_logger(), "Step 2: ⬇️  DIVING to grasp Z=%.3f", grasp_z);
            perform_linear_move(*group, obj.x, obj.y, grasp_z);
            rclcpp::sleep_for(1s);
            
            RCLCPP_WARN(this->get_logger(), "Step 3: 🤏 GRASPING...");
            send_gripper_command(0.0);
            rclcpp::sleep_for(2000ms);
            
            RCLCPP_INFO(this->get_logger(), "Step 4: ⬆️  Lifting to Z=%.3f", lift_z);
            perform_linear_move(*group, obj.x, obj.y, lift_z);
        }
    }

    void execute_intelligent_place(std::shared_ptr<moveit::planning_interface::MoveGroupInterface> group, 
                                   const DetectedObject& loc,
                                   const DetectedObject& obj) {
        RCLCPP_INFO(this->get_logger(), "");
        RCLCPP_INFO(this->get_logger(), "═══ SMART PLACE SEQUENCE ═══");
        
        // Calculate place height: place_z + half of object height
        double half_object_height = obj.height / 2.0;
        double place_dive_z = loc.z + half_object_height;
        double high_z = loc.z + 0.25;
        
        RCLCPP_INFO(this->get_logger(), "Object height: %.3f m", obj.height);
        RCLCPP_INFO(this->get_logger(), "Place surface: %.3f m", loc.z);
        RCLCPP_INFO(this->get_logger(), "Place dive height: %.3f m (surface + %.3f)", 
                   place_dive_z, half_object_height);
        
        // STEP 1: Move above place location
        RCLCPP_INFO(this->get_logger(), "Step 1: Moving above place [%.3f, %.3f, %.3f]", 
                   loc.x, loc.y, high_z);
        plan_and_execute_standard(*group, loc.x, loc.y, high_z);
        rclcpp::sleep_for(1s);
        
        // STEP 2: Dive to place_z + half_object_height
        RCLCPP_WARN(this->get_logger(), "Step 2: ⬇️  DIVING to place height Z=%.3f", place_dive_z);
        perform_linear_move(*group, loc.x, loc.y, place_dive_z);
        rclcpp::sleep_for(1s);
        
        // STEP 3: Release object
        RCLCPP_WARN(this->get_logger(), "Step 3: 🖐️  RELEASING object");
        send_gripper_command(0.038);
        rclcpp::sleep_for(2000ms);
        
        // STEP 4: Retreat upward
        RCLCPP_INFO(this->get_logger(), "Step 4: ⬆️  Retracting to Z=%.3f", high_z);
        perform_linear_move(*group, loc.x, loc.y, high_z);
        
        RCLCPP_INFO(this->get_logger(), "✅ Object placed at height: %.3f m", place_dive_z);
    }

    void execute_push_action(std::shared_ptr<moveit::planning_interface::MoveGroupInterface> group,
                            const DetectedObject& obj) {
        RCLCPP_INFO(this->get_logger(), "═══ PUSH ACTION ═══");
        
        send_gripper_command(0.038);
        rclcpp::sleep_for(1000ms);
        
        plan_and_execute_standard(*group, obj.x - 0.10, obj.y, obj.z);
        perform_linear_move(*group, obj.x + 0.15, obj.y, obj.z);
        perform_linear_move(*group, obj.x - 0.10, obj.y, obj.z);
    }

    void execute_pull_action(std::shared_ptr<moveit::planning_interface::MoveGroupInterface> group,
                            const DetectedObject& obj) {
        RCLCPP_INFO(this->get_logger(), "═══ PULL ACTION ═══");
        
        send_gripper_command(0.038);
        rclcpp::sleep_for(1000ms);
        
        plan_and_execute_standard(*group, obj.x, obj.y, obj.z);
        
        send_gripper_command(0.0);
        rclcpp::sleep_for(2000ms);
        
        perform_linear_move(*group, obj.x - 0.15, obj.y, obj.z);
        
        send_gripper_command(0.038);
        rclcpp::sleep_for(1000ms);
    }

    void spawn_collision_object(const DetectedObject& obj) {
        moveit_msgs::msg::CollisionObject collision_obj;
        collision_obj.header.frame_id = "base_link";
        collision_obj.id = "target_object";
        shape_msgs::msg::SolidPrimitive primitive;
        primitive.type = primitive.CYLINDER;
        primitive.dimensions = {obj.height, obj.width / 2.0};
        geometry_msgs::msg::Pose pose;
        pose.orientation.w = 1.0;
        pose.position.x = obj.x;
        pose.position.y = obj.y;
        pose.position.z = obj.z;
        collision_obj.primitives.push_back(primitive);
        collision_obj.primitive_poses.push_back(pose);
        collision_obj.operation = collision_obj.ADD;
        psi_.applyCollisionObject(collision_obj);
    }

    void remove_object(std::string id) {
        moveit_msgs::msg::CollisionObject obj;
        obj.id = id;
        obj.operation = obj.REMOVE;
        psi_.applyCollisionObject(obj);
    }

    void perform_linear_move(moveit::planning_interface::MoveGroupInterface& group, 
                            double x, double y, double z) {
        std::vector<geometry_msgs::msg::Pose> waypoints;
        waypoints.push_back(create_pose(x, y, z));
        moveit_msgs::msg::RobotTrajectory trajectory;
        group.computeCartesianPath(waypoints, 0.01, trajectory);
        publish_trajectory(trajectory.joint_trajectory);
    }

    bool plan_and_execute_standard(moveit::planning_interface::MoveGroupInterface& group, 
                                   double x, double y, double z) {
        group.setPoseTarget(create_pose(x, y, z));
        moveit::planning_interface::MoveGroupInterface::Plan plan;
        if (group.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS) {
            publish_trajectory(plan.trajectory.joint_trajectory);
            return true;
        }
        return false;
    }

    void plan_and_execute_standard(moveit::planning_interface::MoveGroupInterface& group, 
                                   std::string named_target) {
        group.setNamedTarget(named_target);
        moveit::planning_interface::MoveGroupInterface::Plan plan;
        if (group.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS) 
            publish_trajectory(plan.trajectory.joint_trajectory);
    }

    geometry_msgs::msg::Pose create_pose(double x, double y, double z) {
        geometry_msgs::msg::Pose p;
        p.position.x = x; 
        p.position.y = y; 
        p.position.z = z;
        tf2::Quaternion q;
        q.setRPY(0.0, M_PI, 0.0);
        p.orientation = tf2::toMsg(q);
        return p;
    }

    void publish_trajectory(const trajectory_msgs::msg::JointTrajectory& traj) {
        arm_pub_->publish(traj);
        if (!traj.points.empty()) {
            auto& last = traj.points.back();
            int wait_ms = static_cast<int>((last.time_from_start.sec + 
                         (last.time_from_start.nanosec * 1e-9) + 1.5) * 1000);
            rclcpp::sleep_for(std::chrono::milliseconds(wait_ms));
        }
    }

    void send_gripper_command(double pos) {
        if (!gripper_client_->wait_for_action_server(1s)) return;
        auto goal = GripperAction::Goal();
        goal.command.name = {"gripper_joint"};
        goal.command.position = {pos};
        gripper_client_->async_send_goal(goal);
    }

    rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr arm_pub_;
    rclcpp_action::Client<GripperAction>::SharedPtr gripper_client_;
    rclcpp::Subscription<BBoxList>::SharedPtr obj_sub_;
    moveit::planning_interface::PlanningSceneInterface psi_;
    std::map<std::string, ObjectAffordance> affordance_map_;
    std::map<std::string, ObjectGraspConfig> grasp_config_map_;
    bool action_received_ = false;
    DetectedObject latest_target_;
    DetectedObject latest_place_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PiperDynamicNode>();
    std::thread([node]() { rclcpp::sleep_for(2s); node->run(); }).detach();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
