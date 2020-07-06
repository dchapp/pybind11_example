## How to install

1. `python3 setup.py install --user` (installs PyBind11 extension module `my_module` defined in `my_module.cpp`)
2. `mkdir build && cd build`
3. `conan install .. --build missing` (installs PyBind11 2.3.0 via conan)
4. `cmake ..`
5. `make -j` (builds executable with embedded interpreter)

## How to reproduce

On Windows, compile and run main.cpp using the provided CMakeLists.txt. This should result in the following error:

```
TypeError: Unable to convert function return value to a Python type! The signature was
        (self: embedded_module.wrapper_struct) -> my_struct
```

