# gst-cam

> separating out gstreamer camera ingest code from [`Jetson Utils`](https://github.com/dusty-nv/jetson-utils) into smaller build


## Setup

```
mdir build && cd build && cmake .. && make && ./stream
```

## API

```
the api is starting out the same as dusty's gst camera, things will change as needed
```

## TODO

- [x] setup gst pipeline and msg bus
- [] either diy ringbuffer or boost to handle memory
- [] create capture endpoint to retrieve frames
- [] expose python bindings with pybind

