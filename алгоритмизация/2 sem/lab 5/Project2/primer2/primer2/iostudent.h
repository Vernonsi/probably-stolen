/***************************************************************
 *                                                             *
 * Файл     : iostudent.h                                      *
 *                                                             *
 * Описание : заголовочный файл, описывающий операторы         *
 *            для организации потокового ввода-вывода          *
 *            переменных структурных типов данных              *
 *            STUDENT (Студент) и GROUP (Группа)               *
 *                                                             *
 ***************************************************************/

#ifndef IOSTUDENT_H
#define IOSTUDENT_H

#include <iostream>
#include <fstream>
#include "students.h"
using namespace std;

 // Ввод информации о студенте из потока
istream& operator >> (istream& in, STUDENT& Student);

// Вывод информации о студенте в выходной поток
ostream& operator << (ostream& out, STUDENT Student);

// Ввод информации о группе из входного потока
istream& operator >> (istream& in, GROUP& Group);

// Вывод информации о группе в выходной поток
ostream& operator << (ostream& out, GROUP Group);

// =============== конец заголовочного файла  ==================
#endif
