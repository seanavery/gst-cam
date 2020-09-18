#include <pybind11/pybind11.h>
#include "Camera.cpp"

namespace py = pybind11;

PYBIND11_MODULE(PyCamera, m) 
{
	py::class_<Camera>(m, "Camera")
		.def(py::init<>())
		.def("init", &Camera::init)
		.def("open", &Camera::open)
		.def("capture", &Camera::capture);
}
