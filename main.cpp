
#include <pybind11/embed.h>
#include <pybind11/pybind11.h>

#include <iostream>
#include <memory>

namespace py = pybind11;

struct PYBIND11_EXPORT my_struct {
  std::shared_ptr<int> attr;
  my_struct() {
    attr = std::make_shared<int>(1234);
  }
};

struct PYBIND11_EXPORT wrapper_struct {
  std::shared_ptr<my_struct> my_struct_ptr;
};

PYBIND11_MODULE(module, m) {
  py::class_<my_struct, std::shared_ptr<my_struct>>(m, "my_struct")
    .def(py::init<>())
    .def_readwrite("attr", &my_struct::attr);
}

PYBIND11_EMBEDDED_MODULE(embedded_module, m) {
  py::class_<wrapper_struct>(m, "wrapper_struct")
    .def(py::init<>())
    .def_readwrite("my_struct_ptr", &wrapper_struct::my_struct_ptr);
}

int main() {
  py::scoped_interpreter guard{};
  try {
    py::exec(R"(
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
