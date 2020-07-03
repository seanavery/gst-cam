#include <gst/gst.h>
#include <iostream>
#include <string>

class Camera {
	public:
		GstElement* pipeline;
		void buildPipeline();
};
