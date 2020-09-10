#include <gst/gst.h>
#include <gst/app/gstappsink.h>
#include <iostream>
#include <string>

class Camera {
	public:
		GstElement* launch;
		GstBus* bus;
		GstAppSink* sink;
		int frameCount;
		void init(int argc, char *argv[]);
		bool open();
		bool capture();
	private:
		static void onEOS(_GstAppSink* sink, void* user_data);
		static GstFlowReturn onPreroll(_GstAppSink* sink, void* user_data);
		static GstFlowReturn onBuffer(_GstAppSink* sink, void* user_data);
		void checkBuffer(_GstAppSink* msink);
		void checkMsgBus();
};
