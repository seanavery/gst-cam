#include <pybind11/pybind11.h>
#include "Camera.h"

namespace py = pybind11;

PYBIND11_MODULE(pycamera, m) 
{
	py::class_<Camera>(m, "Camera")
		.def("init", &Camera::init)
		.def("open", &Camera::open)
		.def("caputer", &Camera::caputre)
}
