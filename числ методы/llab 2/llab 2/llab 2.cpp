#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

long double functionValue(long double x) {
	return exp(-x) + pow(x, 2);
}

long double derivativeValue(long double x) {
	return exp(-x) + 2 * x;
}

long double secondDerivativeValue(long double x) {
	return exp(-x) + 2;
}

void right(long double start, long double end, long double shag) {
	cout << "right:      ";
	for (long double i = start; i < end - shag; i += shag) {
		cout << setw(10) <<(functionValue(i + shag) - functionValue(i)) / shag;
	}
	cout << setw(10) << "---";
	cout << "\n";
}

void left(long double start, long double end, long double shag) {
	cout << "left:       ";
	cout << setw(10) << "---";
	for (long double i = start + shag; i < end; i += shag) {
		cout << setw(10) <<(functionValue(i) - functionValue(i - shag)) / shag;
	}
	cout << "\n";
}

void center(long double start, long double end, long double shag) {
	cout << "center:     ";
	cout << setw(10) << "---";
	for (long double i = start + shag; i < end - shag; i += shag) {
		cout << setw(10) <<(functionValue(i + shag) - functionValue(i - shag)) / (2 * shag);
	}
	cout << setw(10) << "---";
	cout << "\n";
}

void Derivative(long double start, long double end, long double shag) {
	cout << "derivative: ";
	for (long double i = start; i < end; i += shag) {
		cout << setw(10) << derivativeValue(i);
	}
	cout << "\n\n";
}

void secondDerivative(long double start, long double end, long double shag) {
	cout << "~second derivative: ";
	cout << setw(10) << "---";
	for (long double i = start + shag; i < end - shag; i += shag) {
		cout << setw(10) <<(functionValue(i + shag) + functionValue(i - shag) - 2 * functionValue(i)) / (shag * shag);
	}
	cout << setw(10) << "---";
	cout << "\n";
}

void realSecondDerivative(long double start, long double end, long double shag) {
	cout << "second derivative: ";
	for (long double i = start; i < end; i += shag) {
		cout << setw(10) << secondDerivativeValue(i);
	}
	cout << "\n\n";
}

int main() {
	setlocale(LC_ALL, "Russian");

	long double start, end, shag;

	cout << "введите начальное значение: ";
	cin >> start;

	cout << "введите конечное значение: ";
	cin >> end;

	cout << "введите шаг: ";
	cin >> shag;

	cout << "\n\n";


	right(start, end, shag);
	left(start, end, shag);
	center(start, end, shag);
	Derivative(start, end, shag);
	secondDerivative(start, end, shag);
	realSecondDerivative(start, end, shag);

	return 0;
}