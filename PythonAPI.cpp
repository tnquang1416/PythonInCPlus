// PythonAPI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Python.h>

int helloFromString();
int helloFromFile();

int main()
{
  std::cout << "Hello World!\n";

  if (helloFromFile() != 0)
    std::cout << "Oppsss\n";

  return 0;
}

int helloFromString() {
  Py_Initialize();
  PyRun_SimpleString("print('Hello World from Python script!')");
  Py_Finalize();

  return 0;
}

int helloFromFile() {
  char path[] = "hello.py";
  FILE* file;

  Py_Initialize();
  file = _Py_fopen(path, "r");
  if (file == NULL)
    return -1;

  PyRun_SimpleFile(file, path);
  Py_Finalize();

  return 0;
}
