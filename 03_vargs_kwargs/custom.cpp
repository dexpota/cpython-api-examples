#include <iostream>
#include <Python.h>


static PyObject *custom_kwargs(PyObject *self, PyObject *args, PyObject *kwargs) {
    PyObject *key, *value;
    Py_ssize_t pos = 0;

    Py_ssize_t size = PyDict_Size(kwargs);

    if(size > 0) {
        while (PyDict_Next(kwargs, &pos, &key, &value)) {
            /* do something interesting with the values... */
            std::cout << PyString_AsString(key) << std::endl;
            std::cout << PyString_AsString(PyObject_Str(value)) << std::endl;
        }
    }

    Py_RETURN_NONE;
}

static PyObject *custom_vargs(PyObject *self, PyObject *args) {
    // The args argument will be a pointer to a Python tuple object containing the arguments.

    size_t nargs = PyTuple_Size(args);
    std::cout << "Number of arguments: " << nargs << std::endl;
    for (size_t i = 0; i < nargs; i++) {
        PyObject *item = PyTuple_GetItem(args, i);


#define TYPE(item, type, name) if(PyObject_TypeCheck(item, &type)) std::cout << name << std::endl;
        TYPE(item, PyTuple_Type, "Tuple")
        TYPE(item, PyString_Type, "String")
        TYPE(item, PyBool_Type, "Bool")
        TYPE(item, PyFloat_Type, "Float")
        TYPE(item, PyLong_Type, "Long")
        TYPE(item, PyInt_Type, "Int")
        TYPE(item, PyList_Type, "List")
        TYPE(item, PyDict_Type, "Dict")
        TYPE(item, PySet_Type, "Set")
        TYPE(item, PyInt_Type, "Long")

    }

    Py_RETURN_NONE;
}

static PyMethodDef custom_methods[] = {
        // METH_VARARGS is the calling convention for this function, arguments are passed in as a tuple
        // METH_KEYWORDS a third PyObject* argument is passed in as a dictionary
        // see https://docs.python.org/2.7/c-api/structures.html#c.PyMethodDef
        {"vargs",  custom_vargs, METH_VARARGS, "Print argument types."},
        {"kwargs",  reinterpret_cast<PyCFunction>(custom_kwargs), METH_KEYWORDS, "Print argument types."},
        {NULL, NULL, 0, NULL}        /* Sentinel */
};

// When python imports module custom for the first time, this function is called.
PyMODINIT_FUNC initcustom(void)
{
    Py_InitModule("custom", custom_methods);
}