import os
import re
import subprocess
from os.path import join

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, GroupAction, ExecuteProcess, TimerAction
from launch.conditions import IfCondition
from launch.conditions import UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.substitutions import PathJoinSubstitution

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

from controller_manager.launch_utils import generate_load_controller_launch_description

def generate_launch_description():

    resources_package = 'spider'

    # Make path to resources dir without last package_name fragment.
    path_to_share_dir_clipped = ''.join(get_package_share_directory(resources_package).rsplit('/' + resources_package, 1))

    # Gazebo hint for resources.
    os.environ['GZ_SIM_RESOURCE_PATH'] = path_to_share_dir_clipped

    # Ensure `SDF_PATH` is populated since `sdformat_urdf` uses this rather

    # than `GZ_SIM_RESOURCE_PATH` to locate resources.
    if "GZ_SIM_RESOURCE_PATH" in os.environ:
        gz_sim_resource_path = os.environ["GZ_SIM_RESOURCE_PATH"]

        if "SDF_PATH" in os.environ:
            sdf_path = os.environ["SDF_PATH"]
            os.environ["SDF_PATH"] = sdf_path + ":" + gz_sim_resource_path
        else:
            os.environ["SDF_PATH"] = gz_sim_resource_path


    use_custom_world = LaunchConfiguration('use_custom_world')
    use_custom_world_launch_arg = DeclareLaunchArgument('use_custom_world', default_value='true')
    gazebo_world = LaunchConfiguration('gazebo_world')
    gazebo_world_launch_arg = DeclareLaunchArgument('gazebo_world', default_value='empty.sdf')

    # prepare custom world
    world = os.getenv('GZ_SIM_WORLD', 'empty')
    fly_world_path = resources_package + '/worlds/' + world + '.sdf'
    gz_version = subprocess.getoutput("gz sim --versions")
    gz_version_major = re.search(r'^\d{1}', gz_version).group()
    launch_arguments=dict(gz_args = '-r ' + str(fly_world_path) + ' --verbose ', gz_version = gz_version_major).items()

    # Gazebo Sim.
    # by default the custom world is used, otherwise the gazebo world is used, which can be changed with the argument
    pkg_ros_gz_sim = get_package_share_directory('ros_gz_sim')
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py'),
        ),
        launch_arguments=launch_arguments if use_custom_world else dict(gz_args='-r ' + gazebo_world + ' --verbose').items(),
    )

    # Spawn
    spawn = Node(
            package='ros_gz_sim',
            executable='create',
            arguments=[
                '-name', 'Robot',
                '-x', '1.2',
                '-z', '1.0',
                '-Y', '3.4',
                '-topic', '/robot_description',
            ],
            output='screen',
    )

    use_sim_time = LaunchConfiguration('use_sim_time')
    use_sim_time_launch_arg = DeclareLaunchArgument('use_sim_time', default_value='true')
    use_rviz = LaunchConfiguration('use_rviz')
    use_rviz_arg = DeclareLaunchArgument("use_rviz", default_value='true')
    use_camera = LaunchConfiguration('use_camera')
    use_camera_launch_arg = DeclareLaunchArgument('use_camera', default_value='true')

    robot_state_publisher = IncludeLaunchDescription(
            PythonLaunchDescriptionSource([
                PathJoinSubstitution([
                    FindPackageShare(resources_package),
                    'launch',
                    'description.launch.py',
                ]),
            ]),
            condition=UnlessCondition(use_rviz),  # rviz launch includes rsp.
            launch_arguments=dict(use_sim_time=use_sim_time).items(),
    )

    rviz = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare(resources_package),
                'launch',
                'display.launch.py',
            ]),
        ]),
        condition=IfCondition(use_rviz),
        launch_arguments=dict(use_sim_time=use_sim_time).items(),
    )

    pkg_share_folder = get_package_share_directory("spider")

    gz_bridge_parameter = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        name='bridge_ros_gz',
        output='screen',
        parameters=[
            {
                'config_file': join(
                    pkg_share_folder, 'config', 'sensors_bridge.yaml'
                ),
                'use_sim_time': True,
            }
        ],
    )

    gz_bridge_camera = Node(
        package='ros_gz_image',
        executable='image_bridge',
        arguments=[
            "/camera_front/image"
        ],
        output='screen',
        parameters=[
            {'use_sim_time': True,
             'camera.image.compressed.jpeg_quality': 75},
        ],
    )
    gz_bridge_camera_dummy = DeclareLaunchArgument('', default_value='') # dummy for LaunchDescription could take empty element


    joint_state_broadcaster = ExecuteProcess(
        cmd=[
            'ros2', 'run', 'controller_manager', 'spawner', 'joint_state_broadcaster',
            '--controller-manager', '/controller_manager',
            '--switch-timeout', '15',
            '--controller-manager-timeout', '15',
            '--service-call-timeout', '15',
            '--param-file', join(pkg_share_folder, 'config', 'spider_controllers.yaml')
        ],
        output='screen',
        condition=UnlessCondition(LaunchConfiguration('gui'))
    )

    spider_leg_back_right_controller = ExecuteProcess(
        cmd=[
            'ros2', 'run', 'controller_manager', 'spawner', 'spider_leg_back_right_controller',
            '--controller-manager', '/controller_manager',
            '--switch-timeout', '15',
            '--controller-manager-timeout', '15',
            '--service-call-timeout', '15',
            '--param-file', join(pkg_share_folder, 'config', 'spider_controllers.yaml')
        ],
        output='screen',
        condition=UnlessCondition(LaunchConfiguration('gui'))
    )

    spider_leg_back_left_controller = ExecuteProcess(
        cmd=[
            'ros2', 'run', 'controller_manager', 'spawner', 'spider_leg_back_left_controller',
            '--controller-manager', '/controller_manager',
            '--switch-timeout', '15',
            '--controller-manager-timeout', '15',
            '--service-call-timeout', '15',
            '--param-file', join(pkg_share_folder, 'config', 'spider_controllers.yaml')
        ],
        output='screen',
        condition=UnlessCondition(LaunchConfiguration('gui'))
    )

    spider_leg_front_right_controller = ExecuteProcess(
        cmd=[
            'ros2', 'run', 'controller_manager', 'spawner', 'spider_leg_front_right_controller',
            '--controller-manager', '/controller_manager',
            '--switch-timeout', '15',
            '--controller-manager-timeout', '15',
            '--service-call-timeout', '15',
            '--param-file', join(pkg_share_folder, 'config', 'spider_controllers.yaml')
        ],
        output='screen',
        condition=UnlessCondition(LaunchConfiguration('gui'))
    )


    spider_leg_front_left_controller = ExecuteProcess(
        cmd=[
            'ros2', 'run', 'controller_manager', 'spawner', 'spider_leg_front_left_controller',
            '--controller-manager', '/controller_manager',
            '--switch-timeout', '15',
            '--controller-manager-timeout', '15',
            '--service-call-timeout', '15',
            '--param-file', join(pkg_share_folder, 'config', 'spider_controllers.yaml')
        ],
        output='screen',
        condition=UnlessCondition(LaunchConfiguration('gui'))
    )

    spider_dome_controller = ExecuteProcess(
        cmd=[
            'ros2', 'run', 'controller_manager', 'spawner', 'spider_dome_controller',
            '--controller-manager', '/controller_manager',
            '--switch-timeout', '15',
            '--controller-manager-timeout', '15',
            '--service-call-timeout', '15',
            '--param-file', join(pkg_share_folder, 'config', 'spider_controllers.yaml')
        ],
        output='screen',
        condition=UnlessCondition(LaunchConfiguration('gui'))
    )
    
    publish_initial_command_1 = TimerAction(
        period=10.0,
        actions=[
            ExecuteProcess(
                cmd=[
                    'ros2', 'topic', 'pub',
                    '/spider_leg_front_left_controller/commands',
                    'std_msgs/msg/Float64MultiArray',
                    'data: [0.0, -1.57, -1.57]',
                    '--once'
                ],
                output='screen'
            )
        ],
        condition=UnlessCondition(LaunchConfiguration('gui'))
    )

    publish_initial_command_2 = TimerAction(
        period=10.0,
        actions=[
            ExecuteProcess(
                cmd=[
                    'ros2', 'topic', 'pub',
                    '/spider_leg_back_left_controller/commands',
                    'std_msgs/msg/Float64MultiArray',
                    'data: [0.0, -1.57, -1.57]',
                    '--once'
                ],
                output='screen'
            )
        ],
        condition=UnlessCondition(LaunchConfiguration('gui'))
    )
    publish_initial_command_3 = TimerAction(
        period=10.0,
        actions=[
            ExecuteProcess(
                cmd=[
                    'ros2', 'topic', 'pub',
                    '/spider_leg_back_right_controller/commands',
                    'std_msgs/msg/Float64MultiArray',
                    'data: [0.0, -1.57, -1.57]',
                    '--once'
                ],
                output='screen'
            )
        ],
        condition=UnlessCondition(LaunchConfiguration('gui'))
    )
    publish_initial_command_4 = TimerAction(
        period=10.0,
        actions=[
            ExecuteProcess(
                cmd=[
                    'ros2', 'topic', 'pub',
                    '/spider_leg_front_right_controller/commands',
                    'std_msgs/msg/Float64MultiArray',
                    'data: [0.0, -1.57, -1.57]',
                    '--once'
                ],
                output='screen'
            )
        ],
        condition=UnlessCondition(LaunchConfiguration('gui'))
    )

    return LaunchDescription([
        use_sim_time_launch_arg,
        use_rviz_arg,
        use_custom_world_launch_arg,
        gazebo_world_launch_arg,
        robot_state_publisher,
        rviz,
        gazebo,
        spawn,
        gz_bridge_parameter,
        joint_state_broadcaster,
        spider_dome_controller,
        spider_leg_front_left_controller,
        spider_leg_front_right_controller,
        spider_leg_back_left_controller,
        spider_leg_back_right_controller,
        (gz_bridge_camera if use_camera else gz_bridge_camera_dummy),
        publish_initial_command_1,
        publish_initial_command_2,
        publish_initial_command_3,
        publish_initial_command_4
    ])
