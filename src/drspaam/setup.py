from setuptools import setup

package_name = 'drspaam'
sub_tracker = 'drspaam/centroid_tracker/'

setup(
    name=package_name,
    version='1.0.0',
    packages=[package_name, sub_tracker],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='taras',
    maintainer_email='tarasz98@gmail.com',
    description='ROS 2 implementation of the 2-D LiDAR person detection DR-SPAAM',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "dr_spaam_node = drspaam.drspaam_node:main",
            "data_streamer = drspaam.data_streamer:main"
        ],
    },
)
