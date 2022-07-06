#include <iostream>
#include <cstdlib>
using namespace std;

struct Point {
    long double x;
    long double y;
};

struct Vector {
    long double x;
    long double y;
    long double length;
};

void enterNumber(long double& n) {
	while (!(cin >> n) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
		cerr << "Введён неверный формат координат точки! Повторите ввод!!!" << endl;
	}
}

void A() {
	double a, b, c,s;
	char aa[255], bb[255], cc[255];
	cout << "Найти площадь треугольника по трем сторонам" << endl;
	cout << "Введите длину первой стороны" << endl;
	cin >> aa;
	cout << "Введите длину второй стороны" << endl;
	cin >> bb;
	cout << "Введите длину третьей стороны" << endl;
	cin >> cc;
	a = atof(aa);
	b = atof(bb);
	c = atof(cc);
	if (a <= 0 || b <= 0 || c <= 0) {
		cerr << "Введены неверные данные";
	}
	else {
		s = sqrt(((a + b + c) / 2) * (a + b + c - a) * (a + b + c - b) * (a + b + c - c));
		cout << "Площадь треугольника " << s;
	}
}

 void C() {
    Point A;
    Point B;
    Point C;
    Point D;
    Vector AD;
    Vector BC;

    cout << "Вычисление длины средней линии трапеции, заданной координатами четырёх вершин" << endl;
    cout << "-----------------------------------------------------------------------------\n" << endl;

    cout << "Введите координаты точки A(x,y)" << endl;
    cout << "Введите A.x: ";
    enterNumber(A.x);
    cout << endl;

    cout << "Введите A.y: ";
    enterNumber(A.y);
    cout << endl;


    cout << "Введите координаты точки B(x,y)" << endl;
    cout << "Введите B.x: ";
    enterNumber(B.x);
    cout << endl;



    cout << "Введите B.y: ";
    enterNumber(B.y);
    cout << endl;

    cout << "Введите координаты точки C(x,y)" << endl;
    cout << "Введите C.x: ";
    enterNumber(C.x);
    cout << endl;

    cout << "Введите C.y: ";
    enterNumber(C.y);
    cout << endl;


    cout << "Введите координаты точки D(x,y)" << endl;
    cout << "Введите D.x: ";
    enterNumber(D.x);
    cout << endl;

    cout << "Введите D.y: ";
    enterNumber(D.y);
    cout << endl;




    AD.x = D.x - A.x;
    AD.y = D.y - A.y;
    AD.length = sqrt(AD.x * AD.x + AD.y * AD.y);

    BC.x = C.x - B.x;
    BC.y = C.y - B.y;
    BC.length = sqrt(BC.x * BC.x + BC.y * BC.y);


    long double middle_line = (AD.length + BC.length) / 2;

    cout << "Длина средней линии: " << middle_line;
}

 void D() {
     cout << " Нахождение точки пересечения двух прямых, проходящих через две пары точек, заданных своими координатами" << endl;
     Point A,B;
     Point C,D;
     Vector AB;
     Vector CD;
     Point X;
     cout << "-----------------------------------------------------------------------------\n" << endl;

     cout << "Введите координаты точки A(x,y)" << endl;
     cout << "Введите A.x: ";
     enterNumber(A.x);
     cout << endl;

     cout << "Введите A.y: ";
     enterNumber(A.y);
     cout << endl;


     cout << "Введите координаты точки B(x,y)" << endl;
     cout << "Введите B.x: ";
     enterNumber(B.x);
     cout << endl;



     cout << "Введите B.y: ";
     enterNumber(B.y);
     cout << endl;

     cout << "Введите координаты точки C(x,y)" << endl;
     cout << "Введите C.x: ";
     enterNumber(C.x);
     cout << endl;

     cout << "Введите C.y: ";
     enterNumber(C.y);
     cout << endl;


     cout << "Введите координаты точки D(x,y)" << endl;
     cout << "Введите D.x: ";
     enterNumber(D.x);
     cout << endl;

     cout << "Введите D.y: ";
     enterNumber(D.y);
     cout << endl;




     AB.x = B.x - A.x;
     AB.y = B.y - A.y;
     AB.length = sqrt(AB.x * AB.x + AB.y * AB.y);

     CD.x = D.x - C.x;
     CD.y = D.y - C.y;
     CD.length = sqrt(CD.x * CD.x + CD.y * CD.y);

     /*X.x=(AB.length*CD.y)/*/

 }

int main() {
	setlocale(0, "Russian");
	int n;
	cout << "Введите номер задачи {1,2,3}" << endl;
	cin >> n;
	switch(n){
	case 1: A();
        break;
	case 2: C();
        break;
	case 3: D();
        break;
	}
}
