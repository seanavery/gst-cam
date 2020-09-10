#include "Camera.cpp"

int main(int argc, char *argv[]) {
	Camera camera;
	camera.init(argc, argv);
	// camera.build();
	// camera.start();
	camera.open();
	
	// caputre in loop
	while (true)
	{
		camera.capture();
	}
}
