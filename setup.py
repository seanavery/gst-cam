import os
import sys
import subprocess
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext

class CMakeExtension(Extension):
    def __init__(self, name, sourcedir='./'):
        Extension.__init__(self, name, sources=[])
        self.sourcedir = os.path.abspath(sourcedir)

class CMakeBuild(build_ext):
    def run(self):
        self.build_temp = './btemp'
        for ext in self.extensions:
            print('here',)
            self.build_extension(ext)
    def build_extension(self, ext):
        extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))
        # required for auto-detection of auxiliary "native" libs
        if not extdir.endswith(os.path.sep):
            extdir += os.path.sep
        env = os.environ.copy()
        env['CXXFLAGS'] = '{} -DVERSION_INFO=\\"{}\\"'.format(env.get('CXXFLAGS', ''),
                                                              self.distribution.get_version())
        if not os.path.exists(self.build_temp):
            os.makedirs(self.build_temp)
            
        subprocess.check_call(['cmake', ext.sourcedir], cwd=self.build_temp, env=env)
        subprocess.check_call(['make'], cwd=self.build_temp)

setup(
    name='PyCamera',
    version='0.0.5',
    author='Sean Pollock',
    description='GStreamer Camera',
    ext_modules=[CMakeExtension('PyCamera')],
    cmdclass=dict(build_ext=CMakeBuild),
)
