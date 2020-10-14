# gst-cam
> slim Camera Capture library that only uses Gstreamer and c++ std library
> runs on on NVidia Jetson Devices with SonyIMX 219 hardware

## What 
This is a port of the gstreamer camera ingest code from [`Jetson Utils`](https://github.com/dusty-nv/jetson-utils). 
The goal was to make a smaller library build that is more portable to my real time apps.

## Setup

### Build
```
# installl pybind11
git submodule init
git sumodule upgrade
mkdir build && cd build && cmake .. && make
```

### Run in c++
You can demo the code with an executable generated called `stream`
```
./stream
```

### Run in python

This library uses Pybind11 to expose the c++ class and bridge type conversions.
The CMake build will also generat a `PyCamera.so` library file that exposes the python module.

```
from PyCamera import Camera
cam = Camera()
cam.init()
cam.start()
while True:
	frame = cam.capture()
```

## TODO

- [x] setup gst pipeline and msg bus
- [ ] either diy ringbuffer or boost to handle memory
- [ ] create capture endpoint to retrieve frames
- [x] expose python bindings with pybind

