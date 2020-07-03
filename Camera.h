#include <gst/gst.h>
#include <iostream>
#include <string>

class Camera {
	public:
		GstElement* pipeline;
		GstBus* bus;
		void init(int argc, char *argv[]);
		void build();
		void start();
		void loop();
};
