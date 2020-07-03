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
	
	this->pipeline = ss.str();
}
