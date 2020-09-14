#include "Camera.cpp"

int main(int argc, char *argv[]) {
	Camera camera;
	camera.init();
	// camera.build();
	// camera.start();
	camera.open();
	
	// caputre in loop
	while (true)
	{
		camera.capture();
	}
}
