from setuptools import find_packages, setup
from glob import glob
package_name = 'ch7_autopartol_robot'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name+'/launch', glob("launch/*.launch.py")),
        ('share/' + package_name+'/config', ['config/partol_config.yaml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='zilu',
    maintainer_email='1301221801@qq.com',
    description='TODO: Package description',
    license='Apache-2.0',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'partol_node=ch7_autopartol_robot.partol_node:main',
            'speaker=ch7_autopartol_robot.speaker:main'
        ],
    },
)
