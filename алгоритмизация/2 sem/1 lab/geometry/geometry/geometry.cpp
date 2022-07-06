﻿/***************************************************************
 *                                                             *
 * Файл     : geometry.cpp                                     *
 *                                                             *
 * Описание : модуль, содержащий реализацию методов классов    *
 *            для решения геометрических задач                 *
 *                                                             *
 ***************************************************************/
#include <iostream>
#include <math.h>
#include "geometry.h"
using namespace std;
 // -------------------------------------------------------------
 //       Методы класса "Точка" 
 // -------------------------------------------------------------

 // конструктор: точка задается своими координатами
Point::Point(double X, double Y) {
    x = X; y = Y;
}

// прочитать координату Х
double Point::getX() {
    return x;
}

// прочитать координату У
double Point::getY() {
    return y;
}

// -------------------------------------------------------------
//       Методы класса "Окружность" 
// -------------------------------------------------------------

// конструктор: окружность задается центром и радиусом
Circle::Circle(Point Center, double R) :center(Center) {
    r = R;
}

// прочитать центр окружности
Point Circle::getCenter() {
    return center;
}

// прочитать радиус окружности
double Circle::getR() {
    return r;
}


// -------------------------------------------------------------
//       Методы класса "Прямая" 
// -------------------------------------------------------------

// конструктор: прямая задается своими коэффициентами
Line::Line(double a, double b, double c) {
    A = a; B = b; C = c;
}

// конструктор: прямая, которая проходит через две заданные точки
Line::Line(Point p1, Point p2) {
    A = p2.getY() - p1.getY();
    B = p1.getX() - p2.getX();
    C = -A * p1.getX() - B * p1.getY();
}

// найти точку пересечения с заданной прямой
Point Line::getIntersect(Line line) {
    double d = A * line.B - B * line.A,
        d1 = -(C * line.B - B * line.C),
        d2 = -(A * line.C - C * line.A);
    return Point(d1 / d, d2 / d);
}

// построить перпендикулярную прямую, проходящую через заданную точку
Line Line::getPerpendicular(Point p) {
    return Line(B, -A, -B * p.getX() + A * p.getY());
}

// -------------------------------------------------------------
//       Методы класса "Отрезок" 
// -------------------------------------------------------------

// конструктор: отрезок задается двумя точками
Segment::Segment(Point p1, Point p2) {
    x1 = p1.getX(); y1 = p1.getY();
    x2 = p2.getX(); y2 = p2.getY();
}

// найти середину отрезка
Point Segment::getMidpoint() {
    return Point((x1 + x2) / 2, (y1 + y2) / 2);
}

// найти длину отрезка
double Segment::getLength() {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// -------------------------------------------------------------
//       Методы класса "Треугольник" 
// -------------------------------------------------------------

// конструктор
Triangle::Triangle( Point A, Point B, Point C) {
    x1 = A.getX(); y1 = A.getY();
    x2 = B.getX(); y2 = B.getY();
    x3 = C.getX(); y3 = C.getY();
    
}


// Выяснить, не лежит ли внутри треугольника точка
bool Triangle::lezhit(Point Z) {
    double x0 = Z.getX(); double y0 = Z.getY();
    double v1 = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
    double v2 = (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
    double v3 = (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);
    if ((v1 > 0 && v2 > 0 && v3 > 0) || (v1 < 0 && v2 < 0 && v3 < 0)) return true;
    else return false;
}



// нехороший вектор
//Vector::Vector(Point A, Point B) {
//    x1 = A.getX(); y1 = A.getY();
//    x2 = B.getX(); y2 = B.getY();
//}
//
//double Vector::getLength() {
//    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
//}
//

Vector::Vector(Point p1, Point p2) {
    this->x = p2.getX() - p1.getX();
    this->y = p2.getY() - p1.getY();
}

long double Vector::scalar_product(Vector v2) {
    return this->x * v2.x + this->y * v2.y;
}

Vector Vector::vector_sum(Vector v1, Vector v2) {
    return Vector(Point(-v1.x, -v1.x), Point(v2.x, v2.y));
}

void Vector::multiply_by_scalar(long double scalar) {
    this->x *= scalar;
    this->y *= scalar;
}

long double Vector::get_x() {
    return this->x;
}

long double Vector::get_y() {
    return this->y;
}

void Vector::info() {
   cout << "\n\n" <<
        "Координата x: " << this->x << "\n"
        "Координата y: " << this->y << endl;
}



// ============== конец модуля =================================
