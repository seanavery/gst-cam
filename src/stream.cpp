#include "Camera.cpp"

int main(int argc, char *argv[]) {
	Camera camera;
	camera.init();
	camera.open();
	while (true)
	{
		camera.capture();
	}
}
