#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>
#include <moveit/planning_scene_interface/planning_scene_interface.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <control_msgs/action/parallel_gripper_command.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <moveit_msgs/msg/robot_trajectory.hpp>
#include <scene_graph_interfaces/msg/fun_object3_d_bounding_box_list.hpp>
#include <scene_graph_interfaces/msg/fun_object3_d_bounding_box.hpp>
#include <std_msgs/msg/string.hpp>

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
        
        // Declare parameters
        this->declare_parameter<std::string>("camera_frame", "camera_link");
        this->declare_parameter<std::string>("robot_base_frame", "base_link");
        
        camera_frame_ = this->get_parameter("camera_frame").as_string();
        robot_base_frame_ = this->get_parameter("robot_base_frame").as_string();
        
        // Initialize TF2
        tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
        tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
        
        // Publishers
        this->arm_pub_ = this->create_publisher<trajectory_msgs::msg::JointTrajectory>(
            "/joint_trajectory_controller/joint_trajectory", 10);
        
        // ✅ NEW: Task state publisher (for graph communication)
        this->task_state_pub_ = this->create_publisher<std_msgs::msg::String>(
            "/task_state", 10);
        
        // ✅ NEW: Object position publisher (for Navigation Module)
        this->object_position_pub_ = this->create_publisher<geometry_msgs::msg::Point>(
            "/object_position", 10);
        
        // Action clients
        this->gripper_client_ = rclcpp_action::create_client<GripperAction>(
            this, "/gripper_controller/gripper_cmd");
        
        // Subscribers
        this->obj_sub_ = this->create_subscription<BBoxList>(
            "/bounding_boxes_3d/rtdetr", 10,
            std::bind(&PiperDynamicNode::vision_callback, this, std::placeholders::_1));
        
        // ✅ NEW: Subscribe to task_state from Navigation Module
        this->task_state_sub_ = this->create_subscription<std_msgs::msg::String>(
            "/task_state", 10,
            std::bind(&PiperDynamicNode::task_state_callback, this, std::placeholders::_1));
        
        initialize_affordances();
        initialize_grasp_configs();
        
        current_task_state_ = "Idle";
        
        RCLCPP_INFO(this->get_logger(), "🤖 Piper Grasping Module Ready!");
        RCLCPP_INFO(this->get_logger(), "   Camera frame: %s", camera_frame_.c_str());
        RCLCPP_INFO(this->get_logger(), "   Robot frame:  %s", robot_base_frame_.c_str());
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
                    // ✅ Publish: Start grasping
                    publish_task_state("Grasp Object");
                    
                    execute_intelligent_grasp(move_group, latest_target_);
                    move_group->attachObject("target_object");
                    
                    execute_intelligent_place(move_group, latest_place_, latest_target_);
                    
                    move_group->detachObject("target_object");
                    
                    // ✅ Publish: Task finished
                    publish_task_state("Task Finished");
                    
                } else if (latest_target_.affordance == Affordance::PUSHABLE) {
                    publish_task_state("Push Object");
                    execute_push_action(move_group, latest_target_);
                    publish_task_state("Task Finished");
                    
                } else if (latest_target_.affordance == Affordance::PULLABLE) {
                    publish_task_state("Pull Object");
                    execute_pull_action(move_group, latest_target_);
                    publish_task_state("Task Finished");
                }

                plan_and_execute_standard(*move_group, "home");
                
                action_received_ = false;
                RCLCPP_INFO(this->get_logger(), "✅ Complete! Waiting for next task...");
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
        affordance_map_["television"] = {Affordance::GRASPABLE, Affordance::NONE};
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
        grasp_config_map_["television"] = {GraspType::TOP_DOWN, "Television - TOP"};
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

    // ✅ NEW: Callback for task_state from Navigation Module
    void task_state_callback(const std_msgs::msg::String::SharedPtr msg) {
        current_task_state_ = msg->data;
        RCLCPP_INFO(this->get_logger(), "📥 Received task state: %s", msg->data.c_str());
        
        // React to specific states if needed
        if (msg->data == "Object Reached") {
            RCLCPP_INFO(this->get_logger(), "✅ Navigation complete, ready to grasp!");
        } else if (msg->data == "Goal Reached") {
            RCLCPP_INFO(this->get_logger(), "✅ Goal reached, ready to place!");
        }
    }

    // ✅ NEW: Publish task state
    void publish_task_state(const std::string& state) {
        auto msg = std_msgs::msg::String();
        msg.data = state;
        task_state_pub_->publish(msg);
        RCLCPP_INFO(this->get_logger(), "📤 Published task state: %s", state.c_str());
    }

    // ✅ NEW: Publish object position (for Navigation Module)
    void publish_object_position(double x, double y, double z) {
        auto msg = geometry_msgs::msg::Point();
        msg.x = x;
        msg.y = y;
        msg.z = z;
        object_position_pub_->publish(msg);
        RCLCPP_INFO(this->get_logger(), "📤 Published object position: [%.3f, %.3f, %.3f]", x, y, z);
    }

    void vision_callback(const BBoxList::SharedPtr msg) {
        if (msg->bbox.empty() || action_received_) return;

        for (const auto& obj : msg->bbox) {
            ObjectAffordance aff = get_affordance(obj.name.data);
            
            if (aff.primary != Affordance::NONE || obj.graspable) {
                try {
                    double cam_x = (obj.bounding_box[0].x + obj.bounding_box[1].x) / 2.0;
                    double cam_y = (obj.bounding_box[0].y + obj.bounding_box[1].y) / 2.0;
                    double cam_z = (obj.bounding_box[0].z + obj.bounding_box[1].z) / 2.0;
                    
                    double width = std::abs(obj.bounding_box[1].x - obj.bounding_box[0].x);
                    double depth = std::abs(obj.bounding_box[1].y - obj.bounding_box[0].y);
                    double height = std::abs(obj.bounding_box[1].z - obj.bounding_box[0].z);
                    
                    RCLCPP_INFO(this->get_logger(), "");
                    RCLCPP_INFO(this->get_logger(), "📷 Camera data: [%.3f, %.3f, %.3f]", cam_x, cam_y, cam_z);
                    
                    geometry_msgs::msg::PoseStamped object_in_camera;
                    object_in_camera.header.frame_id = camera_frame_;
                    object_in_camera.header.stamp = this->now();
                    object_in_camera.pose.position.x = cam_x;
                    object_in_camera.pose.position.y = cam_y;
                    object_in_camera.pose.position.z = cam_z;
                    object_in_camera.pose.orientation.w = 1.0;
                    
                    geometry_msgs::msg::PoseStamped object_in_base;
                    try {
                        object_in_base = tf_buffer_->transform(
                            object_in_camera, 
                            robot_base_frame_, 
                            tf2::durationFromSec(1.0)
                        );
                    } catch (tf2::TransformException &ex) {
                        RCLCPP_ERROR(this->get_logger(), "⚠️  TF2 failed: %s", ex.what());
                        return;
                    }
                    
                    RCLCPP_INFO(this->get_logger(), "🤖 Robot frame (TF): [%.3f, %.3f, %.3f]",
                               object_in_base.pose.position.x,
                               object_in_base.pose.position.y,
                               object_in_base.pose.position.z);
                    
                    latest_target_.class_name = obj.name.data;
                    latest_target_.x = object_in_base.pose.position.x;
                    latest_target_.y = object_in_base.pose.position.y;
                    latest_target_.z = cam_z;
                    latest_target_.width = width;
                    latest_target_.height = height;
                    latest_target_.depth = depth;
                    
                    if (obj.graspable || aff.primary == Affordance::GRASPABLE) {
                        latest_target_.affordance = Affordance::GRASPABLE;
                    } else {
                        latest_target_.affordance = aff.primary;
                    }
                    
                            if (object_in_base.pose.position.x == 0) {
                    latest_place_.x = 0;
                } else {
                    latest_place_.x = -object_in_base.pose.position.x;
                }

                if (object_in_base.pose.position.y == 0) {
                    latest_place_.y = 0;
                } else {
                    latest_place_.y = -object_in_base.pose.position.y;
                }
                   
                    latest_place_.z = cam_z;
                    latest_place_.width = 0;
                    latest_place_.height = height;
                    latest_place_.depth = 0;
                    latest_place_.affordance = Affordance::NONE;
                    
                    RCLCPP_INFO(this->get_logger(), "📍 Pick:  [%.3f, %.3f, %.3f]",
                               latest_target_.x, latest_target_.y, latest_target_.z);
                    RCLCPP_INFO(this->get_logger(), "📦 Place: [%.3f, %.3f, %.3f]",
                               latest_place_.x, latest_place_.y, latest_place_.z);
                    
                    // ✅ NEW: Publish object position for Navigation Module
                    publish_object_position(latest_target_.x, latest_target_.y, latest_target_.z);
                    
                    // ✅ NEW: Publish task state
                    publish_task_state("Navigate");
                    
                    action_received_ = true;
                    break;
                    
                } catch (const std::exception& e) {
                    RCLCPP_ERROR(this->get_logger(), "❌ Error: %s", e.what());
                }
            }
        }
    }

    void execute_intelligent_grasp(std::shared_ptr<moveit::planning_interface::MoveGroupInterface> group, 
                                   const DetectedObject& obj) {
        GraspType grasp_type = get_grasp_type(obj.class_name, obj);
        
        send_gripper_command(0.038);
        rclcpp::sleep_for(1500ms);

        if (grasp_type == GraspType::SIDE) {
            RCLCPP_WARN(this->get_logger(), "═══ SIDE GRASP ═══");
            
            double object_bottom = obj.z - (obj.height / 2.0);
            double grasp_height = object_bottom + (obj.height * 0.5) + 0.2;
            double high_z = obj.z + 0.25;
            
            RCLCPP_INFO(this->get_logger(), "Step 1: Above [%.3f, %.3f, %.3f]", obj.x, obj.y, high_z);
            plan_and_execute_standard(*group, obj.x, obj.y, high_z);
            rclcpp::sleep_for(1s);
            
            RCLCPP_WARN(this->get_logger(), "Step 2: ⬇️  Dive to Z=%.3f", grasp_height);
            perform_linear_move(*group, obj.x, obj.y, grasp_height);
            rclcpp::sleep_for(1s);
            
            RCLCPP_WARN(this->get_logger(), "Step 3: 🤏 Grasp");
            send_gripper_command(0.0);
            rclcpp::sleep_for(2000ms);
            
            RCLCPP_INFO(this->get_logger(), "Step 4: ⬆️  Lift");
            perform_linear_move(*group, obj.x, obj.y, high_z);
            
        } else {
            RCLCPP_INFO(this->get_logger(), "═══ TOP GRASP ═══");
            
            double high_z = obj.z + 0.25;
            double grasp_z = obj.z;
            
            plan_and_execute_standard(*group, obj.x, obj.y, high_z);
            rclcpp::sleep_for(1s);
            
            perform_linear_move(*group, obj.x, obj.y, grasp_z);
            rclcpp::sleep_for(1s);
            
            send_gripper_command(0.0);
            rclcpp::sleep_for(2000ms);
            
            perform_linear_move(*group, obj.x, obj.y, high_z);
        }
    }
void execute_intelligent_place(std::shared_ptr<moveit::planning_interface::MoveGroupInterface> group, 
                               const DetectedObject& loc,
                               const DetectedObject& obj) {
    RCLCPP_INFO(this->get_logger(), "");
    RCLCPP_INFO(this->get_logger(), "═══ PLACE SEQUENCE ═══");
    
    double half_object_height = obj.height / 2.0;
    double place_dive_z = (loc.z - (obj.height / 2.0)) + ((obj.height * 0.5) + 0.2);
    double high_z = loc.z + 0.26;
    
    // Step 1: Move above place location
    RCLCPP_INFO(this->get_logger(), "Step 1: 📍 Above place [%.3f, %.3f, %.3f]", loc.x, loc.y, high_z);
    plan_and_execute_standard(*group, loc.x, loc.y, high_z);
    rclcpp::sleep_for(1s);
    
    // Step 2: Dive down to place height
    RCLCPP_WARN(this->get_logger(), "Step 2: ⬇️  Diving to Z=%.3f", place_dive_z);
    perform_linear_move(*group, loc.x, loc.y, place_dive_z);
    rclcpp::sleep_for(1s);
    
    // Step 3: Release object
    RCLCPP_WARN(this->get_logger(), "Step 3: 🖐️  Releasing gripper");
    send_gripper_command(0.038);
    rclcpp::sleep_for(2000ms);
    
// Step 4: Lift up
    RCLCPP_INFO(this->get_logger(), "Step 4: ⬆️ Lifting to Z=%.3f", high_z);
    perform_linear_move(*group, loc.x, loc.y, high_z);
    rclcpp::sleep_for(500ms);
    
// Step 5: ✅ DIRECTIONAL RETRACT on X-axis
    double retract_distance = 0.15; // 15cm
    double retract_x;

    // If the object is in front (positive X), move closer to the base (subtract)
    // If the object is behind (negative X), move closer to the base (add)
    if (loc.x >= 0) {
        retract_x = loc.x - retract_distance;
    } else {
        retract_x = loc.x + retract_distance;
    }

    RCLCPP_WARN(this->get_logger(), "Step 5: ⬅️ Retracting on X-axis (X: %.3f → %.3f)", 
                loc.x, retract_x);
    
    // Perform the linear retraction while keeping Y and Z stable
    perform_linear_move(*group, retract_x, loc.y, high_z);
    rclcpp::sleep_for(500ms);
    
    RCLCPP_INFO(this->get_logger(), "✅ Place complete - safe to return home");
}

    void execute_push_action(std::shared_ptr<moveit::planning_interface::MoveGroupInterface> group,
                            const DetectedObject& obj) {
        RCLCPP_INFO(this->get_logger(), "═══ PUSH ═══");
        send_gripper_command(0.038);
        rclcpp::sleep_for(1000ms);
        plan_and_execute_standard(*group, obj.x - 0.10, obj.y, obj.z);
        perform_linear_move(*group, obj.x + 0.15, obj.y, obj.z);
        perform_linear_move(*group, obj.x - 0.10, obj.y, obj.z);
    }

    void execute_pull_action(std::shared_ptr<moveit::planning_interface::MoveGroupInterface> group,
                            const DetectedObject& obj) {
        RCLCPP_INFO(this->get_logger(), "═══ PULL ═══");
        send_gripper_command(0.038);
        rclcpp::sleep_for(1000ms);
        plan_and_execute_standard(*group, obj.x, obj.y, obj.z);
        send_gripper_command(0.0);
        rclcpp::sleep_for(2000ms);
        perform_linear_move(*group, obj.x - 0.15, obj.y, obj.z);
        send_gripper_command(0.038);
        rclcpp::sleep_for(1000ms);
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

    // Member variables
    rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr arm_pub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr task_state_pub_;           // ✅ NEW
    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr object_position_pub_;  // ✅ NEW
    
    rclcpp_action::Client<GripperAction>::SharedPtr gripper_client_;
    
    rclcpp::Subscription<BBoxList>::SharedPtr obj_sub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr task_state_sub_;        // ✅ NEW
    
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
    
    std::string camera_frame_;
    std::string robot_base_frame_;
    std::string current_task_state_;  // ✅ NEW
    
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
