#include <gst/gst.h>
#include "Camera.h"
#include <iostream>
#include <sstream>

using namespace std;

void Camera::init(int argc, char *argv[]) 
{
	gst_init(&argc, &argv);
};

void Camera::build() 
{
	ostringstream ss;
	ss << "nvarguscamerasrc wbmode=1 ! ";
	ss << "nvvidconv flip-method=2 ! ";
	ss << "videoconvert ! video/x-raw, format=(string)BGR ! ";
	ss << "appsink";
	this->pipeline = gst_parse_launch(ss.str().c_str(), NULL);
};

void Camera::start() 
{
	gst_element_set_state(this->pipeline, GST_STATE_PLAYING);
	this->bus = gst_element_get_bus(pipeline);
	this->loop();
};

void Camera::loop() {
	while(true)
	{
		GstMessage* msg = gst_bus_pop(this->bus);

		if (!msg)
		{
			break;
		}
	}
}
