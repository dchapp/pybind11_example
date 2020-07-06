//
// Created by dchapp on 7/6/20.
//

#ifndef MINREP_APP_MY_STRUCT_H
#define MINREP_APP_MY_STRUCT_H

#include <pybind11/embed.h>
#include <pybind11/pybind11.h>

#include <memory>
#include <string>

struct PYBIND11_EXPORT my_struct {
  int attr{1234};
};

#endif //MINREP_APP_MY_STRUCT_H
