#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

using namespace std;

string gstreamer_pipeline (int capture_width, int capture_height, int display_width, int display_height, int framerate, int flip_method) {
		return "nvarguscamerasrc wbmode=1 ! nvvidconv flip-method=2 ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";
}

int main(int argc, char *argv[])
{
	cout << "brining up camera (SonyIMX219)" << endl;
	
	int capture_width = 1920;
	int capture_height = 1080;
	int display_width = 1920;
	int display_height = 1080;
	int framerate = 30;
	int flip_method = 2;

	// gstreamer libargus capture
	string pipeline = gstreamer_pipeline(capture_width,
		capture_height,
		display_width,
		display_height,
		framerate,
		flip_method);

	cout << "gstreamer pipeline: \n" << pipeline << "\n";
	
	cv::VideoCapture cap(pipeline, cv::CAP_GSTREAMER);
	if (!cap.isOpened()) {
		cout << "failed to open camera" << endl;
		return -1;
	}

	cv::namedWindow("camera", cv::WINDOW_AUTOSIZE);
	cv::Mat img;
	
	std::cout << "hit ESC to exit" << "\n";

	while(true)
	{
		if (!cap.read(img)) {
			cout << "capture read error" << endl;
			break;
		}
		
		cv::imshow("camera", img);
		int keycode = cv::waitKey(1) & 0xff;
		if (keycode == 27) break;
	}

	cap.release();
	cv::destroyAllWindows();
	return 0;
}

