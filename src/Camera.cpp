#include <gst/gst.h>
#include <gst/app/gstappsink.h>
#include "Camera.h"
#include <iostream>
#include <sstream>

using namespace std;

void Camera::init() 
{
	// init
	cout << "gstreamer camera" << endl;
	// gst_init(&argc, &argv);
	this->frameCount = 0;
	
	// build
	ostringstream ss;
	ss << "nvarguscamerasrc wbmode=1 sensor_id=0 ! ";
	ss << "nvvidconv flip-method=2 ! ";
	// ss << "videoconvert ! video/x-raw, format=(string)BGR ! ";
	ss << "appsink name=mysink";
	GError* err = NULL;
	cout << ss.str() << endl;
	this->launch = gst_parse_launch(ss.str().c_str(), &err);
	if (err != NULL) 
	{	
		cout << err << endl;
		g_error_free(err);
		return;
	}
	cout << ss.str() << endl;
	
	// start
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
	GstElement* appsinkElement = gst_bin_get_by_name(GST_BIN(pipeline), "mysink");
	if (!appsinkElement)
	{
		cout << "could not create appsink element" << endl;
		return;
	}
	sink = GST_APP_SINK(appsinkElement);
	if (!sink)
	{
		cout << "could not create appsink" << endl;
		return;
	}
	// this->sink = appsink;
	GstAppSinkCallbacks cb;
	memset(&cb, 0, sizeof(GstAppSinkCallbacks));
	cb.eos = onEOS;
	cb.new_preroll = onPreroll;
	cb.new_sample = this->onBuffer;
	gst_app_sink_set_callbacks(sink, &cb, (void*)this, NULL);
	// GstAppSink* appsinkElement = gst_bin_get_by_name(GST_BIN(
	// gst_element_set_state(this->pipeline, GST_STATE_PLAYING);
	// this->bus = gst_element_get_bus(this->pipeline);
	// this->loop();
};

void Camera::onEOS(_GstAppSink* sink, void* user_data)
{
	cout << "hit end of stream" << endl;
};

GstFlowReturn Camera::onBuffer(_GstAppSink* sink, void* user_data)
{
	cout << "hit onBuffer" << endl;
	if (!user_data)
	{
		return GST_FLOW_OK;
	}

	cout << user_data << endl;

	Camera* dec = (Camera*)user_data;

	dec->checkBuffer(sink);
	dec->checkMsgBus();
	return GST_FLOW_OK;
};

GstFlowReturn Camera::onPreroll(_GstAppSink* sink, void* user_data)
{
	cout << "camera preroll" << endl;
	return GST_FLOW_OK;
};

void Camera::checkBuffer(_GstAppSink* msink) 
{
	cout << "inside checkBuffer" << endl;
	this->frameCount = this->frameCount + 1;
	cout << "frame count " << frameCount << endl;
	if (!sink)
	{
		cout << "sink is not defined" << endl;
		return;
	}
	cout << typeid(sink).name() << endl;
	cout << GST_IS_APP_SINK(sink) << endl;
	GstSample* gstSample = gst_app_sink_pull_sample(sink);
	if (!gstSample)
	{
		cout << "app sink pull error" << endl;
		return;
	}
	GstBuffer* gstBuff = gst_sample_get_buffer(gstSample);
	if (!gstBuff)
	{
		cout << "could not convert sink sample to buffer" << endl;
		return;
	}
	GstMapInfo map;
	if (!gst_buffer_map(gstBuff, &map, GST_MAP_READ))
	{
		cout << "gst_buffer_map() failed" << endl;
		return;
	}
	const void* data = map.data;
	const gsize maxsize = map.maxsize;
	cout << "maxsize" << maxsize << endl;
	GstCaps* gstCaps = gst_sample_get_caps(gstSample);
	if (!gstCaps)
	{
		cout << "could not retrieve caps" << endl;
		return;
	}
	GstStructure* gstCapsStruct = gst_caps_get_structure(gstCaps, 0);
	if (!gstCapsStruct)
	{
		cout << "could not create gstCapsStruct" << endl;
		return;
	}
	int width = 0;
	gst_structure_get_int(gstCapsStruct, "width", &width);
	cout << "width: " << width << endl;
	int height = 0;
	gst_structure_get_int(gstCapsStruct, "height", &height);
	cout << "height: " << height << endl;
	gst_sample_unref(gstSample);
	gst_buffer_unmap(gstBuff, &map);
	return;
};

void Camera::checkMsgBus() 
{
	cout << "check msg bus" << endl;
	while (true) 
	{
		cout << "before" << endl;
		GstMessage* msg = gst_bus_pop(this->bus);
		cout << "after" << endl;
		if (!msg)
		{
			cout << "no message ..." << endl;
			break;
		}

		cout << "got message!" << msg << endl;
		gst_message_unref(msg);
	}
}

bool Camera::open() 
{
	if (!this->launch)
	{
		cout << "must init camera before openeing" << endl;
		return false;
	}
	// change state of pipeline
	const GstStateChangeReturn result = gst_element_set_state(this->launch, GST_STATE_PLAYING);

	cout << result << endl;
	cout << GST_STATE_CHANGE_SUCCESS << endl;
	cout << GST_STATE_CHANGE_ASYNC << endl;
	
	if (result == GST_STATE_CHANGE_ASYNC)
	{
		cout << "here 0" << endl;
#if 0
		GstMessage* asyncMsg = gst_bus_timed_pop_filtered(this->bus, 5 * GST_SECOND, (GstMessageType)(GST_MESSAGE_ASYNC_DONE|GST_MESSAGE_ERROR));
		cout << "here 1" << endl;
		if (asyncMsg != NULL)
		{
		// 	// gst_message_print(this->bus, asyncMsg, this);
			gst_message_unref(asyncMsg);
		// 	cout << "nooooo goood async msg" << endl;
		// 	cout << asyncMsg << endl;
		}
#endif
	}
	else if (result != GST_STATE_CHANGE_SUCCESS)
	{
		cout << "could not change state to playing" << endl;
		return false;
	}
	cout << "first check msg bus" << endl;
	checkMsgBus();
	g_usleep(100*1000);
	cout << "second check msg bus" << endl;
	checkMsgBus();
	cout << "its the end now" << endl;
}

bool Camera::capture() {
	return true;
}
