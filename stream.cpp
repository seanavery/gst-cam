#include "Camera.cpp"

int main(int argc, char *argv[]) {
	Camera camera;
	camera.init(argc, argv);
	camera.buildPipeline();
}
