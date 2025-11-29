from setuptools import find_packages
from setuptools import setup

setup(
    name='spider_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('spider_msgs', 'spider_msgs.*')),
)
