/***************************************************************
**
* ����     : students.h*
**
* �������� : ������������ ����, ����������� ����������� ����*
* ������ STUDENT(�������) � GROUP(������)*
**
***************************************************************/

#ifndef STUDENTS_H
#define STUDENTS_H

// ------- �������� ������������ ���� ������ ������� -----------
struct STUDENT {
	char LastName[15];     // �������
	char FirstName[15];    // ���
	char MiddleName[15];   // ��������
	int Number;            // ����� �������������
};

// ------- �������� ������������ ���� ������ ������ ------------
struct GROUP {
	char Name[5];          // �������� ������
	int N;                 // ���������� ���������
	STUDENT* Student;     // ������ ���������
};

#endif

// =============== ����� ������������� �����  ==================
