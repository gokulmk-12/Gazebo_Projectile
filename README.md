# Gazebo_Projectile
This Repo has the file necessary to implement Projectile Motion in 3-D Gazebo Physics Environment using ROS Topics

# Steps to Add the plugin to your model
Add the following line at the end of model.sdf 
```
<plugin name="" filename="libprojectile_plugin.so"></plugin>
```

# Steps to use the plugin
Step 1: Clone the Repository in a ROS Workspace and catkin_make

```
cd <your_workspace>/src
git clone https://github.com/gokulmk-12/Gazebo_Projectile.git
cd ../
catkin_make
```
Step 2: You can use any object model to test. I have used a simple cardboard box, and a launch file to spawn in Gazebo

```
roslaunch Gazebo_Projectile box.launch
```
Step 3: Publish the velocity values to the topic **/model_move** (geometry_msgs/Twist) (2-D)

```
rostopic pub /model_move geometry_msgs/Twist "linear:
  x: 5.0
  y: 0.0
  z: 3.0
angular:
  x: 0.0
  y: 0.0
  z: 0.0
```
https://github.com/gokulmk-12/Gazebo_Projectile/assets/113512290/f124312a-dfdb-44b2-8701-7f3599b29026

Step 4: Publish the velocity values to the topic **/model_move** (geometry_msgs/Twist) (3-D)

```
rostopic pub /model_move geometry_msgs/Twist "linear:
  x: 5.0
  y: 2.0
  z: 3.0
angular:
  x: 0.0
  y: 0.0
  z: 0.0
```
https://github.com/gokulmk-12/Gazebo_Projectile/assets/113512290/972b54f1-b3a9-46ce-b5b9-41fd9580c022

