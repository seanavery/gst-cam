from setuptools import setup, Extension, find_packages
module=Extension('PyCamera', sources=['static/pycamera.cpython-36m-aarch64-linux-gnu.so'])
print("""
        adf
        adfa
        adfad
        """)
setup(
    name='PyCamera',
    version='0.0.4',
    author='Sean Pollock',
    description='GStreamer Camera',
    # packages=find_packages(),
    # package_data={'PyCamera': ['pycamera.cpython-36m-aarch64-linux-gnu.so']},
    # include_package_data=True,
    # ext_modules=[]
    package_data={'PyCamera': ['pycamera_cypython_aarch64.so']},
    zip_safe=False, 
)
