#include <iostream>
#include <Python.h>


static PyObject *custom_hello_world(PyObject *self, PyObject *args) {
    std::cout << "Hello World! From C++." << std::endl;
    Py_RETURN_NONE;
}

static PyMethodDef custom_methods[] = {
        // METH_VARARGS is the calling convention for this function, arguments are passed in as a tuple
        // METH_KEYWORDS a third PyObject* argument is passed in as a dictionary
        // see https://docs.python.org/2.7/c-api/structures.html#c.PyMethodDef
        {"hello_world",  custom_hello_world, METH_NOARGS, "Say hello world!"},
        {NULL, NULL, 0, NULL}        /* Sentinel */
};

// When python imports module custom for the first time, this function is called.
PyMODINIT_FUNC initcustom(void)
{
    Py_InitModule("custom", custom_methods);
}