#include <pybind11/pybind11.h>
#include "Camera.cpp"

namespace py = pybind11;

void init(Camera *camera) {
	camera->init();
}

PYBIND11_MODULE(PyCamera, m) 
{
	py::class_<Camera>(m, "Camera")
		.def("init", &Camera::init)
		.def("open", &Camera::open)
		.def("capture", &Camera::capture);

	m.def("init", &init);
}
