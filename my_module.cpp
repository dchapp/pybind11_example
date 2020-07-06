//
// Created by dchapp on 7/6/20.
//

#include "my_struct.h"

#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(my_module, m) {
py::class_<my_struct, std::shared_ptr<my_struct>>(m, "my_struct")
.def(py::init<>())
.def_readwrite("attr", &my_struct::attr);
}

