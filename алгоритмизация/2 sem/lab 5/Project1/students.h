***************************************************************
 *                                                             *
 * Файл     : students.h                                       *
 *                                                             *
 * Описание : заголовочный файл, описывающий структурные типы  *
 *            данных STUDENT (Студент) и GROUP (Группа)        *
 *                                                             *
 ***************************************************************/

#ifndef STUDENTS_H
#define STUDENTS_H

// ------- описание структурного типа данных СТУДЕНТ -----------
struct STUDENT {
  char LastName[15];     // Фамилия
  char FirstName[15];    // Имя
  char MiddleName[15];   // Отчество
  int Number;            // Номер студенческого
};

// ------- описание структурного типа данных ГРУППА ------------
struct GROUP {
  char Name[5];          // Название группы
  int N;                 // Количество студентов
  STUDENT * Student;     // Массив студентов
};

#endif

// =============== конец заголовочного файла  ==================
