#include <gst/gst.h>
#include <gst/app/gstappsink.h>
#include <iostream>
#include <string>

class Camera {
	public:
		GstElement* launch;
		GstBus* bus;
		GstAppSink* sink;
		void init(int argc, char *argv[]);
		void build();
		void start();
		void loop();
		bool capture();
	private:
		static void onEOS(_GstAppSink* sink, void* user_data);
		static GstFlowReturn onPreroll(_GstAppSink* sink, void* user_data);
		static GstFlowReturn onBuffer(_GstAppSink* sink, void* user_data);
};
