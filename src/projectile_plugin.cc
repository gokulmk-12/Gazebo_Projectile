#include <gazebo/gazebo.hh>
#include <gazebo/common/common.hh>
#include <gazebo/physics/physics.hh>
#include <ignition/math/Vector3.hh>     
#include <ros/ros.h>                     
#include <std_msgs/Bool.h>
#include <geometry_msgs/Twist.h>

//  Using the Plugin 
//  <plugin name="" filename="libprojectile_plugin.so"></plugin>

namespace gazebo{
    class ProjectileRosPlugin : public ModelPlugin{
        public:
            void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf){

                if (!ros::isInitialized())
                {
                    ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized");
                }

                ROS_WARN("ROS Projectile Plugin Loaded !");

                this->sub = this->nh.subscribe("/model_move", 10, &ProjectileRosPlugin::Active_Callback, this);

                this->model = _model;

                std::cout<<"Model Name = " << this->model->GetName() << std::endl;

                this->updateConnection = event::Events::ConnectWorldUpdateBegin(
                    std::bind(&ProjectileRosPlugin::OnUpdate, this));
            }

        public:
            void Active_Callback(const geometry_msgs::Twist::ConstPtr& msg){
                ROS_WARN("Recieved Message = %f, %f, %f", msg->linear.x, msg->linear.y, msg->linear.z);
                this->velx = msg->linear.x;
                this->vely = msg->linear.y;
                this->velz = msg->linear.z;
                // this->activate_move = msg->data;
            }
        
        public:
            void OnUpdate(){
                if (this->velx != 0.0 and this->count < 100)
                {
                    this->model->SetLinearVel(ignition::math::Vector3d(this->velx, this->vely, this->velz));
                    this->count++;
                }
                else if (this->count > 100)
                {
                    this->model->SetLinearVel(ignition::math::Vector3d(0, 0, 0));
                    this->count++;
                } 
                else if (this->count == 100){
                    this->count = 0;
                    this->velx = 0;
                }
            }
        private:
            physics::ModelPtr model;
    
        private:
            int count;
            double velx;
            double vely;
            double velz;

            private:
            event::ConnectionPtr updateConnection;

            private:
            ros::NodeHandle nh;
            ros::Subscriber sub;
            bool activate_move;
    };
    GZ_REGISTER_MODEL_PLUGIN(ProjectileRosPlugin)
}