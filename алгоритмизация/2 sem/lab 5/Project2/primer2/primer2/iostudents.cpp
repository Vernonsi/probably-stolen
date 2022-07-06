/***************************************************************
 *                                                             *
 * ����     : iostudent.cpp                                    *
 *                                                             *
 * �������� : ���������� ���������� ��� ����������� ���������� *
 *            �����-������ ���������� ����������� �����        *
 *            ������ STUDENT (�������) � GROUP (������)        *
 *                                                             *
 ***************************************************************/

#include "iostudent.h"
#include <iostream>
using namespace std;

 // ======= ���� ���������� � �������� �� �������� ������ =======
istream& operator >> (istream& in, STUDENT& Student)
{
    in >> Student.LastName;
    in >> Student.FirstName;
    in >> Student.MiddleName;
    in >> Student.Number;
    return in;
}

// ======= ����� ���������� � �������� � �������� ����� ========
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

// ======= ���� ���������� � ������ �� �������� ������ =========
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

// ====== ����� ���������� � ������ � �������� ����� ===========
ostream& operator << (ostream& out, GROUP Group)
{
    out << "������ ������ " << Group.Name << endl;
    for (int i = 0; i < Group.N; i++) out << Group.Student[i];
    return out;
}

// ====================== ����� ������ =========================
