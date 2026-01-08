import os
import re
import subprocess
from os.path import join

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, ExecuteProcess, TimerAction
from launch.conditions import IfCondition, UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import (
    LaunchConfiguration,
    PathJoinSubstitution,
    TextSubstitution,
)

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():

    # ------------------------------------------------
    # Package
    # ------------------------------------------------
    resources_package = 'spider'
    path_to_share_dir_clipped = ''.join(get_package_share_directory(resources_package).rsplit('/' + resources_package, 1))

    # ------------------------------------------------
    # Gazebo resource paths
    # ------------------------------------------------
    # Make path to resources dir without last package_name fragment.

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

    # ------------------------------------------------
    # Launch arguments
    # ------------------------------------------------
    use_sim_time = LaunchConfiguration('use_sim_time')
    use_rviz = LaunchConfiguration('use_rviz')
    use_custom_world = LaunchConfiguration('use_custom_world')
    world_name = LaunchConfiguration('world_name')
    use_camera = LaunchConfiguration('use_camera')

    declare_args = [
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        DeclareLaunchArgument('use_rviz', default_value='true'),
        DeclareLaunchArgument('use_custom_world', default_value='false'),
        DeclareLaunchArgument('world_name', default_value='empty'),
        DeclareLaunchArgument('use_camera', default_value='true'),
    ]

    # ------------------------------------------------
    # World path
    # ------------------------------------------------
    world_path = PathJoinSubstitution([
        FindPackageShare(resources_package),
        'worlds',
        [world_name, '.sdf']
    ])

    # ------------------------------------------------
    # Gazebo version
    # ------------------------------------------------
    gz_version = subprocess.getoutput("gz sim --versions")
    gz_version_major = re.search(r'^\d+', gz_version).group()

    pkg_ros_gz_sim = get_package_share_directory('ros_gz_sim')

    # ------------------------------------------------
    # Gazebo with custom world
    # ------------------------------------------------
    gazebo_custom_world = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            join(pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py'),
        ),
        launch_arguments={
            'gz_args': [
                TextSubstitution(text='-r '),
                world_path,
                TextSubstitution(text=' --verbose')
            ],
            'gz_version': gz_version_major,
        }.items(),
        condition=IfCondition(use_custom_world),
    )

    # ------------------------------------------------
    # Gazebo empty world (default)
    # ------------------------------------------------
    gazebo_empty_world = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            join(pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py'),
        ),
        launch_arguments={
            'gz_args': '-r empty.sdf --verbose',
            'gz_version': gz_version_major,
        }.items(),
        condition=UnlessCondition(use_custom_world),
    )

    # ------------------------------------------------
    # Spawn robot
    # ------------------------------------------------
    spawn = Node(
        package='ros_gz_sim',
        executable='create',
        arguments=[
            '-name', 'Robot',
            '-x', '0.0',  # Centro de la habitación
            '-y', '0.0',
            '-z', '1.0',  # Altura desde el suelo
            '-Y', '0.0',
            '-topic', '/robot_description',
        ],
        output='screen',
    )

    # ------------------------------------------------
    # Robot description / RViz
    # ------------------------------------------------
    robot_state_publisher = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([
                FindPackageShare(resources_package),
                'launch',
                'description.launch.py',
            ])
        ),
        condition=UnlessCondition(use_rviz),
        launch_arguments={'use_sim_time': use_sim_time}.items(),
    )

    rviz = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([
                FindPackageShare(resources_package),
                'launch',
                'display.launch.py',
            ])
        ),
        condition=IfCondition(use_rviz),
        launch_arguments={'use_sim_time': use_sim_time}.items(),
    )

    # ------------------------------------------------
    # Sensors bridge
    # ------------------------------------------------
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

    # -------------------------------
    # Controllers
    # -------------------------------
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
        period=10.5,  # Esperar 5 segundos antes de ejecutar
        actions=[
            ExecuteProcess(
                cmd=[
                    'timeout', '20',
                    'ros2', 'topic', 'pub',
                    '/spider_leg_front_left_controller/commands',
                    'std_msgs/msg/Float64MultiArray',
                    'data: [0.0, 0.0, 0.0]',
                    '--once'
                ],
                output='screen',
                condition=UnlessCondition(LaunchConfiguration('gui'))
            )
        ]
    )

    publish_initial_command_2 = TimerAction(
        period=10.5,
        actions=[
            ExecuteProcess(
                cmd=[
                    'timeout', '20',
                    'ros2', 'topic', 'pub',
                    '/spider_leg_back_left_controller/commands',
                    'std_msgs/msg/Float64MultiArray',
                    'data: [0.0, 0.0, 0.0]',
                    '--once'
                ],
                output='screen',
                condition=UnlessCondition(LaunchConfiguration('gui'))
            )
        ]
    )

    publish_initial_command_3 = TimerAction(
        period=10.5,
        actions=[
            ExecuteProcess(
                cmd=[
                    'timeout', '20',
                    'ros2', 'topic', 'pub',
                    '/spider_leg_back_right_controller/commands',
                    'std_msgs/msg/Float64MultiArray',
                    'data: [0.0, 0.0, 0.0]',
                    '--once'
                ],
                output='screen',
                condition=UnlessCondition(LaunchConfiguration('gui'))
            )
        ]
    )

    publish_initial_command_4 = TimerAction(
        period=10.5,
        actions=[
            ExecuteProcess(
                cmd=[
                    'timeout', '20',
                    'ros2', 'topic', 'pub',
                    '/spider_leg_front_right_controller/commands',
                    'std_msgs/msg/Float64MultiArray',
                    'data: [0.0, 0.0, 0.0]',
                    '--once'
                ],
                output='screen',
                condition=UnlessCondition(LaunchConfiguration('gui'))
            )
        ]
    )

    return LaunchDescription(
        declare_args + [
        gazebo_custom_world,
        gazebo_empty_world,
        robot_state_publisher,
        rviz,
        spawn,
        gz_bridge_parameter,
        (gz_bridge_camera if use_camera else gz_bridge_camera_dummy),
        joint_state_broadcaster,
        spider_dome_controller,
        spider_leg_front_left_controller,
        spider_leg_front_right_controller,
        spider_leg_back_left_controller,
        spider_leg_back_right_controller,
        publish_initial_command_1,
        publish_initial_command_2,
        publish_initial_command_3,
        publish_initial_command_4
    ])
