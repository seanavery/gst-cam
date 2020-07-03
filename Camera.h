#include <gst/gst.h>

#include <iostream>
#include <string>

class Camera {
	public:
		std::string pipeline;	
		void buildPipeline();
};
