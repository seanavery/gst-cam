cmake_minimum_required(VERSION 2.8)
project( CudaMotionDetect )
# find_package( OpenCV REQUIRED )
# include_directories(/usr/include/gstreamer-1.0 /usr/lib/aarch64-linux-gnu/gstreamer-1.0/include/ /usr/include/glib-2.0/)

include_directories(/usr/include/gstreamer-1.0 /usr/lib/aarch64-linux-gnu/gstreamer-1.0/include /usr/include/glib-2.0 /usr/include/libxml2 /usr/lib/aarch64-linux-gnu/glib-2.0/include/)

add_executable( stream stream.cpp )
# target_link_libraries( Stream ${OpenCV_LIBS} )
