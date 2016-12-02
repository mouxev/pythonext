#include <Python.h>

static PyObject* helloworld(PyObject* self)
{
    return Py_BuildValue("s", "Hello, Python extensions!!");
}

static char helloworld_docs[] =
    "helloworld( ): Any message you want to put here!!\n";

static PyMethodDef helloworld_funcs[] = {
    {"helloworld", (PyCFunction)helloworld, 
     METH_NOARGS, helloworld_docs},
    {NULL}
};

static struct PyModuleDef hellomodule = {
    PyModuleDef_HEAD_INIT,
    "hello", /* module name */
    NULL, /* module documentation, may be NULL */
    -1,
    helloworld_funcs /* the methods array */
};

PyMODINIT_FUNC PyInit_helloworld(void)
{
    return PyModule_Create(&hellomodule);
}