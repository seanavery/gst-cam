#include <gst/gst.h>
#include "Camera.h"
#include <iostream>
#include <sstream>

using namespace std;

void Camera::buildPipeline() {
	ostringstream ss;
	ss << "nvarguscamerasrc wbmode=1 ! ";
	ss << "nvvidconv flip-method=2 ! ";
	ss << "videoconvert ! video/x-raw, format=(string)BGR ! ";
	ss << "appsink";
	// string pipelineStr = ss.str();
	this->pipeline = gst_parse_launch(ss.str().c_str(), NULL);
}
