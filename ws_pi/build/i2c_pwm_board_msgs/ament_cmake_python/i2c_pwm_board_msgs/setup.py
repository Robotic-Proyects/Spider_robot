from setuptools import find_packages
from setuptools import setup

setup(
    name='i2c_pwm_board_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('i2c_pwm_board_msgs', 'i2c_pwm_board_msgs.*')),
)
