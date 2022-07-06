/***************************************************************
 *                                                             *
 * Файл     : main.cpp                                         *
 *                                                             *
 * Описание : главный файл проекта для демонстрации            *
 *            потокового ввода-вывода структурных типов        *
 *            данных STUDENT (Студент) и GROUP (Группа)        *
 *                                                             *
 ***************************************************************/

#include <iostream.h>
#include <fstream.h>
#include <windows.h>

#include "students.h"
#include "iostudent.h"

int main(int argc, char* argv[])
  {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
