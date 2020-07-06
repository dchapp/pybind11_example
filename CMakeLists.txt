cmake_minimum_required(VERSION 3.15)
project(minrep_app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Python COMPONENTS Interpreter Development)

set(PYBIND11_PYTHON_VERSION 3.6.9)
find_package(pybind11 REQUIRED)

# Prevent linker errors caused by the dependencies of PyBind's interface library target 
set(LIBS "${Python_LIBRARIES}")
list(REMOVE_ITEM LIBS "optimized")
list(REMOVE_ITEM LIBS "debug")

add_executable(main)
target_sources(main PUBLIC main.cpp)
target_include_directories(main PUBLIC "${Python_INCLUDE_DIRS}")
target_link_libraries(main PUBLIC "${LIBS}")
