#include "my_struct.h"

#include <pybind11/embed.h>
#include <pybind11/pybind11.h>

#include <iostream>
#include <memory>

namespace py = pybind11;

struct PYBIND11_EXPORT wrapper_struct {
  std::shared_ptr<my_struct> my_struct_ptr{std::make_shared<my_struct>()};
};

PYBIND11_EMBEDDED_MODULE(embedded_module, m) {
  py::class_<wrapper_struct>(m, "wrapper_struct")
    .def(py::init<>())
    .def_readwrite("my_struct_ptr", &wrapper_struct::my_struct_ptr);
}

int main() {
  py::scoped_interpreter guard{};
  try {
    py::exec(R"(
    import my_module
    import embedded_module
    ws = embedded_module.wrapper_struct()
    print(ws.my_struct_ptr) # Error on attribute access
    )");
  }
  catch (const py::error_already_set& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
