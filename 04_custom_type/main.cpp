#include <iostream>
#include <Python.h>
#include <abstract.h>
#include "custom.h"

int main() {
    Py_Initialize();
    PyObject *module_name;
    module_name = PyString_FromString("test");

    CustomType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&CustomType) < 0)
        return -1;

    PyObject *module = PyImport_Import(module_name);
    PyModule_AddObject(module, "Noddy", (PyObject *)&CustomType);
    //PyObject_SetAttrString(module, "Noddy", (PyObject *)&CustomType);
    Py_DECREF(module_name);

    PyObject *function = PyObject_GetAttrString(module, "foo");

    PyObject *arglist = PyTuple_New(0);
    PyObject *value = PyEval_CallObject(function, arglist);

    Py_DECREF(function);
    Py_DECREF(module);
    Py_Finalize();
    return 0;
}