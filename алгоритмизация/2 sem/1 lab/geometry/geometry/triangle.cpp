//***************************************************************
//**
//* Файл     : triangle.cpp*
//**
//* Описание : главный файл проекта для демонстрации*
//* использования объектов для решения*
//* геометрических задач*
//**
//***************************************************************
//**
//* Дано     : Координаты вершин треугольника.*
//* Найти : Описанную около этого треугольника окружность.*
//**
//*************************************************************** /

#include <windows.h>
#include "geometry.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    SetConsoleOutputCP(1251);

    // ----- ввод исходных данных -----
    double x1, y1, x2, y2, x3, y3;
    cout << "Введите координаты первой точки ===> ";
    cin >> x1 >> y1;
    cout << "Введите координаты второй точки ===> ";
    cin >> x2 >> y2;
    cout << "Введите координаты третьей точки ==> ";
    cin >> x3 >> y3;
    double x0, y0;
    cout << "Введите координаты ищущейся точки ==> ";
    cin >> x0 >> y0;
    // ----- создание точек - вершин треугольника -----
    Point A = Point(x1, y1),
        B = Point(x2, y2),
        C = Point(x3, y3);
    Point Z = Point(x0, y0);

   /* double v1 = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
    double v2 = (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
    double v3 = (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);*/

    /*double v1 = (A.getX() - Z.getX()) * (B.getY() - A.getY()) - (B.getX() - A.getX()) * (A.getY() - Z.getY());
    double v2 = (B.getX() - Z.getX()) * (C.getY() - B.getY()) - (C.getX() - B.getX()) * (B.getY() - Z.getY());
    double v3 = (C.getX() - Z.getX()) * (A.getY() - C.getY()) - (A.getX() - C.getX()) * (C.getY() - Z.getY());
    if ((v1 > 0 && v2 > 0 && v3 > 0) || (v1 < 0 && v2 < 0 && v3 < 0)) cout << "lezhit \n";
    else cout << "ne lezhit\n";*/
    Triangle a = Triangle (A,B,C);
    if (a.lezhit(Z)) cout << "\nlezhit";
    else cout << "\nne lezhit";


   // // ----- создание отрезков - сторон треугольника -----
   // Segment Otrezok1 = Segment(A, B),
   //     Otrezok2 = Segment(B, C);

   // // ----- создание точек - середин сторон треугольника -----
   // Point S1 = Otrezok1.getMidpoint(),
   //     S2 = Otrezok2.getMidpoint();

   // // ----- создание прямых, проходящих через стороны треугольника -----
   // Line line1 = Line(A, B),
   //     line2 = Line(B, C),
   //     // ----- ... и серединных перепндикуляров к этим сторонам ... -----
   //     midperpendicular1 = line1.getPerpendicular(S1),
   //     midperpendicular2 = line2.getPerpendicular(S2);

   // // ----- нахождение точки пересечения серединных перпендикуляров -----
   // Point O = midperpendicular1.getIntersect(midperpendicular2);

   // // ----- создание отрезка - радиуса -----
   // Segment Radius = Segment(O, A);

   // // ----- создание окружности с заданным центром и радиусом -----
   // Circle circle = Circle(O, Radius.getLength());

   // // ----- вывод результата -----
   ///* cout << "Центр окружности расположен в точке ("
   //     << circle.getCenter().getX() << ',' << circle.getCenter().getY()
   //     << "), радиус = " << circle.getR() << endl;*/


    /*Sleep(9999);*/
    return 0;
}

// ================= конец программы ===========================
