from setuptools import find_packages
from setuptools import setup

setup(
    name='ch3_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('ch3_interfaces', 'ch3_interfaces.*')),
)
