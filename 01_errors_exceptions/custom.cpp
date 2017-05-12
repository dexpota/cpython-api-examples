#include <iostream>
#include <Python.h>
#include <string>

static PyObject *CustomError;

PyObject *custom_value_error(PyObject *self, PyObject *args) {
    // When a function fails, it should set an exception condition
    // and return an error value (usually a NULL pointer)

    PyErr_SetString(PyExc_ValueError, "This is Value error! originating from C.");

    return NULL;
}

PyObject *custom_error(PyObject *self, PyObject *args) {
    // When a function fails, it should set an exception condition
    // and return an error value (usually a NULL pointer)

    PyErr_SetString(CustomError, "This is custom error! originating from C.");

    return NULL;
}


static PyMethodDef custom_methods[] = {
        // see https://docs.python.org/2.7/c-api/structures.html#c.PyMethodDef
        {"value_error",  custom_value_error, METH_NOARGS, "Raise a ValueError."},
        {"custom_error",  custom_error, METH_NOARGS, "Raise a custom error."},
        {NULL, NULL, 0, NULL}        /* Sentinel */
};

// When python imports module custom for the first time, this function is called.
PyMODINIT_FUNC initcustom(void)
{
    PyObject *m = Py_InitModule("custom", custom_methods);

    CustomError = PyErr_NewException(const_cast<char *>("custom.error"), NULL, NULL);
    Py_INCREF(CustomError);
    PyModule_AddObject(m, "error", CustomError);

}