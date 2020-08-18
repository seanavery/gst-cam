#include <gst/gst.h>
#include <gst/app/gstappsink.h>
#include "Camera.h"
#include <iostream>
#include <sstream>

using namespace std;

void Camera::init(int argc, char *argv[]) 
{
	cout << "gstreamer camera" << endl;
	gst_init(&argc, &argv);
};

void Camera::build() 
{
	ostringstream ss;
	ss << "nvarguscamerasrc wbmode=1 ! ";
	ss << "nvvidconv flip-method=2 ! ";
	ss << "videoconvert ! video/x-raw, format=(string)BGR ! ";
	ss << "appsink name=sink";
	GError* err = NULL;
	this->launch = gst_parse_launch(ss.str().c_str(), &err);
	if (err != NULL) 
	{	
		cout << err << endl;
		g_error_free(err);
		return;
	}
	cout << ss.str() << endl;
};

void Camera::start() 
{
	GstPipeline* pipeline = GST_PIPELINE(this->launch);
	if (!pipeline)
	{
		cout << "could not create GST pipeline" << endl;
		return;
	}
	this->bus = gst_pipeline_get_bus(pipeline);
	if (!this->bus)
	{
		cout << "could not create bus element" << endl;
		return;
	}
	GstElement* appsinkElement = gst_bin_get_by_name(GST_BIN(pipeline), "sink");
	if (!appsinkElement)
	{
		cout << "could not create appsink element" << endl;
		return;
	}
	GstAppSink* appsink = GST_APP_SINK(appsinkElement);
	// if (!appsink)
	// {
	// 	cout << "could not create appsink" << endl;
	// 	return;
	// }
	// GstAppSink* appsinkElement = gst_bin_get_by_name(GST_BIN(
	// gst_element_set_state(this->pipeline, GST_STATE_PLAYING);
	// this->bus = gst_element_get_bus(this->pipeline);
	// this->loop();
};
