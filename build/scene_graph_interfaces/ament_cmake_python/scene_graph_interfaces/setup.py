from setuptools import find_packages
from setuptools import setup

setup(
    name='scene_graph_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('scene_graph_interfaces', 'scene_graph_interfaces.*')),
)
