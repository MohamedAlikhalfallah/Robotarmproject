#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <control_msgs/action/parallel_gripper_command.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <moveit_msgs/msg/robot_trajectory.hpp>
#include <cmath>
#include <vector>
#include <chrono>

using namespace std::chrono_literals;

struct DetectedObject {
    std::string name;
    double x, y, z;
};

class PiperDynamicNode : public rclcpp::Node {
public:
    using GripperAction = control_msgs::action::ParallelGripperCommand;

    PiperDynamicNode() : Node("piper_dynamic_engine") {
        this->set_parameter(rclcpp::Parameter("use_sim_time", true));
        this->arm_pub_ = this->create_publisher<trajectory_msgs::msg::JointTrajectory>(
            "/joint_trajectory_controller/joint_trajectory", 10);
        this->gripper_client_ = rclcpp_action::create_client<GripperAction>(
            this, "/gripper_controller/gripper_cmd");
            
        RCLCPP_INFO(this->get_logger(), "🤖 Piper Dynamic Engine - Jazzy Collision-Fix Version");
    }

    void run() {
        auto move_group = std::make_shared<moveit::planning_interface::MoveGroupInterface>(
            shared_from_this(), "manipulator");
        
        move_group->setPlanningTime(20.0);
        move_group->setNumPlanningAttempts(20);
        move_group->setMaxVelocityScalingFactor(0.15);
        move_group->setGoalPositionTolerance(0.005); 
        move_group->setGoalOrientationTolerance(0.05);

        DetectedObject red_cube;
        red_cube.x = 0.2179;
        red_cube.y = 0.146;
        red_cube.z = 1.02;

        plan_and_execute_standard(*move_group, "home");
        execute_robust_pick(move_group, red_cube);
        
        DetectedObject place_loc;
        place_loc.x = 0.20; place_loc.y = 0.15; place_loc.z = 1.10;
        execute_robust_place(move_group, place_loc);

        plan_and_execute_standard(*move_group, "home");
    }

private:
    void execute_robust_pick(std::shared_ptr<moveit::planning_interface::MoveGroupInterface> group, const DetectedObject& obj) {
        
        double high_z  = obj.z + 0.20; 
        double low_z   = obj.z + 0.10; 
        double grasp_z = obj.z - 0.005; // Slightly higher to clear table collision box

        // 1. Max Open Before Picking
        RCLCPP_INFO(this->get_logger(), "▶ STEP 1: Opening gripper to maximum...");
        send_gripper_command(0.038);
        rclcpp::sleep_for(1500ms);

        // 2. High Approach
        RCLCPP_INFO(this->get_logger(), "▶ STEP 2: High Approach...");
        plan_and_execute_standard(*group, obj.x, obj.y, high_z, "HIGH_PRE_GRASP");

        // 3. Low Approach
        RCLCPP_INFO(this->get_logger(), "▶ STEP 3: Low Approach...");
        if (!plan_and_execute_standard(*group, obj.x, obj.y, low_z, "LOW_PRE_GRASP")) {
            RCLCPP_WARN(this->get_logger(), "Low approach tight, increasing tolerance...");
            group->setGoalPositionTolerance(0.03); 
            plan_and_execute_standard(*group, obj.x, obj.y, low_z, "LOW_PRE_GRASP_RELAXED");
            group->setGoalPositionTolerance(0.005);
        }

        // 4. Final Descent (Forced Cartesian/Joint Hybrid)
        RCLCPP_INFO(this->get_logger(), "▶ STEP 4: Final Descent to Grasp...");
        std::vector<geometry_msgs::msg::Pose> waypoints;
        waypoints.push_back(create_pose(obj.x, obj.y, grasp_z));
        moveit_msgs::msg::RobotTrajectory trajectory;
        
        // Using Jazzy's 3-argument signature for Cartesian planning
        double fraction = group->computeCartesianPath(waypoints, 0.005, trajectory);
        
        if (fraction > 0.3) {
            publish_trajectory(trajectory.joint_trajectory);
        } else {
            RCLCPP_WARN(this->get_logger(), "Cartesian descent aborted. Attempting Direct Position Plan.");
            group->setGoalPositionTolerance(0.04); // Large tolerance to bypass collision near table
            plan_and_execute_standard(*group, obj.x, obj.y, grasp_z, "DIRECT_DESCENT");
            group->setGoalPositionTolerance(0.005);
        }

        // 5. Close Completely After Picking
        RCLCPP_INFO(this->get_logger(), "▶ STEP 5: Closing gripper completely...");
        send_gripper_command(0.0);
        rclcpp::sleep_for(2000ms);

        // 6. Post-Grasp Retreat
        RCLCPP_INFO(this->get_logger(), "▶ STEP 6: Lifting object...");
        perform_linear_move(*group, obj.x, obj.y, high_z, "POST_GRASP_LIFT");
    }

    void execute_robust_place(std::shared_ptr<moveit::planning_interface::MoveGroupInterface> group, const DetectedObject& loc) {
        plan_and_execute_standard(*group, loc.x, loc.y, loc.z + 0.15, "PRE_PLACE");
        perform_linear_move(*group, loc.x, loc.y, loc.z, "PLACE_DESCEND");
        
        // 7. Open Completely Before Placing
        RCLCPP_INFO(this->get_logger(), "▶ Opening gripper to maximum for release...");
        send_gripper_command(0.038);
        rclcpp::sleep_for(2000ms);
        
        perform_linear_move(*group, loc.x, loc.y, loc.z + 0.15, "POST_PLACE_RETREAT");
    }

    void perform_linear_move(moveit::planning_interface::MoveGroupInterface& group, double x, double y, double z, std::string label) {
        std::vector<geometry_msgs::msg::Pose> waypoints;
        waypoints.push_back(create_pose(x, y, z));
        moveit_msgs::msg::RobotTrajectory trajectory;
        
        double fraction = group.computeCartesianPath(waypoints, 0.01, trajectory);
        
        if (fraction > 0.5) {
            publish_trajectory(trajectory.joint_trajectory);
        } else {
            plan_and_execute_standard(group, x, y, z, label);
        }
    }

    bool plan_and_execute_standard(moveit::planning_interface::MoveGroupInterface& group, double x, double y, double z, std::string label) {
        group.setPoseTarget(create_pose(x, y, z));
        moveit::planning_interface::MoveGroupInterface::Plan plan;
        if (group.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS) {
            publish_trajectory(plan.trajectory.joint_trajectory);
            return true;
        }
        return false;
    }

    void plan_and_execute_standard(moveit::planning_interface::MoveGroupInterface& group, std::string named_target) {
        group.setNamedTarget(named_target);
        moveit::planning_interface::MoveGroupInterface::Plan plan;
        if (group.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS) {
            publish_trajectory(plan.trajectory.joint_trajectory);
        }
    }

    geometry_msgs::msg::Pose create_pose(double x, double y, double z) {
        geometry_msgs::msg::Pose p;
        p.position.x = x; p.position.y = y; p.position.z = z;
        tf2::Quaternion q;
        // Pointing straight down
        q.setRPY(0.0, M_PI, 0.0); 
        p.orientation = tf2::toMsg(q);
        return p;
    }

    void publish_trajectory(const trajectory_msgs::msg::JointTrajectory& traj) {
        arm_pub_->publish(traj);
        if (!traj.points.empty()) {
            auto& last = traj.points.back();
            double sec = last.time_from_start.sec + (last.time_from_start.nanosec * 1e-9);
            int wait_ms = static_cast<int>((sec + 1.5) * 1000);
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
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PiperDynamicNode>();
    std::thread([node]() { rclcpp::sleep_for(3000ms); node->run(); }).detach();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
