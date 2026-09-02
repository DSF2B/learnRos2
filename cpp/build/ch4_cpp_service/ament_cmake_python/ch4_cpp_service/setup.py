from setuptools import find_packages
from setuptools import setup

setup(
    name='ch4_cpp_service',
    version='0.0.0',
    packages=find_packages(
        include=('ch4_cpp_service', 'ch4_cpp_service.*')),
)
