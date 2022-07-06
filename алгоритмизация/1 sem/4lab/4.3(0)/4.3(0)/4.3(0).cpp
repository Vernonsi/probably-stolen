#include <iostream>
#include <math.h>
using namespace std;

void for_(double x,double h) {
	double z=h;
	double g = 0;
	for (int i = 0; abs(z) >= h; i++) {
		z = pow(-1, i)*(pow(x,2*i+1)/(2*i+1));
		g = g + z;
	}
	cout << "\n for " << g;
}
void while_(double x, double h) {
	double z = h;
	double g = 0;
	int i = -1;
	while (abs(z) >= h) {
		i++;
		z = pow(-1, i) * (pow(x, 2 * i + 1) / (2 * i + 1));
		g = g + z;
	}
	cout << "\n while " << g;
}
void dowhile(double x, double h) {
	double z = h;
	double g = 0;
	int i = -1;
	do {
		i++;
		z = pow(-1, i) * (pow(x, 2 * i + 1) / (2 * i + 1));
		g = g + z;
	} while (abs(z) >= h);
	cout << "\n do while " << g;
}

int main() {
	setlocale(0, "Russian");
	double  x,h,z;
	cout << "Введите x\n";
	cin >> x;
	cout << "Введите точность\n";
	cin >> h;
	for_(x, h);
	while_(x, h);
	dowhile(x, h);
	z = atan(x);
	cout << "\n atan " << z;
}