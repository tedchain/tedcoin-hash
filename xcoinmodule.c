#include <Python.h>

#include "tedcoin.h"

static PyObject *tedcoin_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    tedcoin_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    tedcoin_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef TedcoinMethods[] = {
    { "getPoWHash", tedcoin_getpowhash, METH_VARARGS, "Returns the proof of work hash using tedcoin hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef TedcoinModule = {
    PyModuleDef_HEAD_INIT,
    "tedcoin_hash",
    "...",
    -1,
    TedcoinMethods
};

PyMODINIT_FUNC PyInit_tedcoin_hash(void) {
    return PyModule_Create(&TedcoinModule);
}

#else

PyMODINIT_FUNC inittedcoin_hash(void) {
    (void) Py_InitModule("tedcoin_hash", TedcoinMethods);
}
#endif
