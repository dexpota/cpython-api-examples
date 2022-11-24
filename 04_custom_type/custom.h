//
// Created by fabrizio destro on 4/29/17.
//

#ifndef _CUSTOM_H
#define _CUSTOM_H

#include <Python.h>
#include <structmember.h>

typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */

    PyObject *first;
    PyObject *last;
    int number;
} Custom;

PyObject *Custom_new(PyTypeObject *type, PyObject *args, PyObject *kwds);
void Custom_dealloc(Custom* self);
int Custom_init(Custom *self, PyObject *args, PyObject *kwds);
PyObject *Custom_name(Custom* self);
int Custom_setfirst(Custom *self, PyObject *value, void *closure);
PyObject *Custom_getfirst(Custom *self, void *closure);


static PyMethodDef Custom_methods[] = {
        {"name", (PyCFunction)Custom_name, METH_NOARGS,
                "Return the name, combining the first and last name"
        },
        {NULL}  /* Sentinel */
};

static PyMemberDef Custom_members[] = {
        {"last", T_OBJECT_EX, offsetof(Custom, last), 0,
                "last name"},
        {"number", T_INT, offsetof(Custom, number), 0,
                "noddy number"},
        {NULL}  /* Sentinel */
};

static PyGetSetDef Custom_getseters[] = {
        {"first",
                (getter)Custom_getfirst, (setter)Custom_setfirst,
                "first name",
                NULL},
        {NULL}  /* Sentinel */
};

static PyTypeObject CustomType = {
        PyVarObject_HEAD_INIT(NULL, 0)
        "noddy.Noddy",             /* tp_name */
        sizeof(Custom),             /* tp_basicsize */
        0,                         /* tp_itemsize */
        (destructor)Custom_dealloc, /* tp_dealloc */
        0,                         /* tp_print */
        0,                         /* tp_getattr */
        0,                         /* tp_setattr */
        0,                         /* tp_compare */
        0,                         /* tp_repr */
        0,                         /* tp_as_number */
        0,                         /* tp_as_sequence */
        0,                         /* tp_as_mapping */
        0,                         /* tp_hash */
        0,                         /* tp_call */
        0,                         /* tp_str */
        0,                         /* tp_getattro */
        0,                         /* tp_setattro */
        0,                         /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT |
        Py_TPFLAGS_BASETYPE,   /* tp_flags */
        "Noddy objects",           /* tp_doc */
        0,                         /* tp_traverse */
        0,                         /* tp_clear */
        0,                         /* tp_richcompare */
        0,                         /* tp_weaklistoffset */
        0,                         /* tp_iter */
        0,                         /* tp_iternext */
        Custom_methods,             /* tp_methods */
        Custom_members,             /* tp_members */
        Custom_getseters,                         /* tp_getset */
        0,                         /* tp_base */
        0,                         /* tp_dict */
        0,                         /* tp_descr_get */
        0,                         /* tp_descr_set */
        0,                         /* tp_dictoffset */
        (initproc)Custom_init,      /* tp_init */
        0,                         /* tp_alloc */
        Custom_new,                 /* tp_new */
};

#endif //_CUSTOM_H
