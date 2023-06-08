from setuptools import setup

package_name = 'yolo_pose_ros'
sub_utils = "yolo_pose_ros/utils/"
sub_models = "yolo_pose_ros/models/"
sub_tracker = "yolo_pose_ros/centroid_tracker"

setup(
    name=package_name,
    version='1.0.0',
    packages=[package_name, sub_utils, sub_models, sub_tracker],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='taras',
    maintainer_email='tarasz98@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "yolo_pose_node = yolo_pose_ros.yolo_pose_node:main"
        ],
    },
)
