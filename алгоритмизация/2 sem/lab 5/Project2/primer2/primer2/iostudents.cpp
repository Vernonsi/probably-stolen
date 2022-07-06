/***************************************************************
 *                                                             *
 * Файл     : iostudent.cpp                                    *
 *                                                             *
 * Описание : реализация операторов для организации потокового *
 *            ввода-вывода переменных структурных типов        *
 *            данных STUDENT (Студент) и GROUP (Группа)        *
 *                                                             *
 ***************************************************************/

#include "iostudent.h"
#include <iostream>
using namespace std;

 // ======= Ввод информации о студенте из входного потока =======
istream& operator >> (istream& in, STUDENT& Student)
{
    in >> Student.LastName;
    in >> Student.FirstName;
    in >> Student.MiddleName;
    in >> Student.Number;
    return in;
}

// ======= Вывод информации о студенте в выходной поток ========
ostream& operator << (ostream& out, STUDENT Student)
{
    out.width(8);
    out.fill('0');
    out << Student.Number << " "
        << Student.LastName << " "
        << Student.FirstName[0] << ". "
        << Student.MiddleName[0] << ".\n";
    return out;
}

// ======= Ввод информации о группе из входного потока =========
istream& operator >> (istream& in, GROUP& Group)
{
    in >> Group.Name;
    in >> Group.N;
    Group.Student = new STUDENT[Group.N];
    for (int i = 0; i < Group.N; i++)
    {
        in >> Group.Student[i];
    }
    return in;
}

// ====== Вывод информации о группе в выходной поток ===========
ostream& operator << (ostream& out, GROUP Group)
{
    out << "Список группы " << Group.Name << endl;
    for (int i = 0; i < Group.N; i++) out << Group.Student[i];
    return out;
}

// ====================== конец модуля =========================
