#include <iostream>
#include <Python.h>


static PyObject *python_callback = NULL;

static PyObject *custom_set_callback(PyObject *self, PyObject *args)
{
    PyObject *result = NULL;
    PyObject *temp;

    if (PyArg_ParseTuple(args, "O:set_callback", &temp)) {
        if (!PyCallable_Check(temp)) {
            PyErr_SetString(PyExc_TypeError, "parameter must be callable");
            return NULL;
        }
        Py_XINCREF(temp);         /* Add a reference to new 02_callback */
        Py_XDECREF(python_callback);  /* Dispose of previous 02_callback */
        python_callback = temp;       /* Remember new 02_callback */

    }

    Py_RETURN_NONE;
}


static PyObject *custom_call_callback(PyObject *self, PyObject *args){
    if(python_callback and PyCallable_Check(python_callback)){
        PyObject *result = PyObject_CallObject(python_callback, NULL);

        if (result == NULL)
            return NULL; /* Pass error back */
        Py_DECREF(result);
    }
    Py_RETURN_NONE;
}


static PyMethodDef custom_methods[] = {
        // see https://docs.python.org/2.7/c-api/structures.html#c.PyMethodDef
        {"set_callback",  custom_set_callback, METH_VARARGS, "Set a callback."},
        {"call_callback",  custom_call_callback, METH_NOARGS, "Call a callback."},
        {NULL, NULL, 0, NULL}        /* Sentinel */
};

// When python imports module custom for the first time, this function is called.
PyMODINIT_FUNC initcustom(void)
{
    PyObject *m = Py_InitModule("custom", custom_methods);
}