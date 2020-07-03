#include <gst/gst.h>
#include <iostream>
#include <string>

class Camera {
	public:
		GstElement* pipeline;
		void init(int argc, char *argv[]);
		void buildPipeline();
};
