#include <Python.h>

void
main() {
    // Загрузка интерпретатора Python
    Py_Initialize();
    // Выполнение команды в интерпретаторе
    PyRun_SimpleString("print('Hello!')");
    // Выгрузка интерпретатора Python
    Py_Finalize();
}