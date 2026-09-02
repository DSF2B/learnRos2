from setuptools import find_packages
from setuptools import setup

setup(
    name='ch3_status_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('ch3_status_interfaces', 'ch3_status_interfaces.*')),
)
