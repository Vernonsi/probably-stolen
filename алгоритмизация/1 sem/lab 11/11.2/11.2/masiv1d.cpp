#include "Header.h"
#include <iostream>
#include <string>
using namespace std;
void vvod(long double* masiv, long double* masiv_1, double num) {
	cout << "Введите массив" << endl;
	for (int i = 0; i < num; i++) {
		cin >> masiv[i];

		masiv_1[i] = masiv[i];
	}

}

void vivod(long double* masiv, double num) {
	cout << endl;
	for (int i = 0; i < num; i++) cout << masiv[i] << " ";
}

void vozr(long double* masiv, double num) {
	double a;
	double v = num;
	while (v != 0) {
		for (int i = 1; i < num; i++) {
			if (masiv[i - 1] > masiv[i]) {
				a = masiv[i - 1];
				masiv[i - 1] = masiv[i];
				masiv[i] = a;
			}
		}
		v--;
	}

}



void yb(long double* masiv, double num) {
	double a;
	double v = num;
	while (v != 0) {
		for (int i = 1; i < num; i++) {
			if (masiv[i - 1] < masiv[i]) {
				a = masiv[i - 1];
				masiv[i - 1] = masiv[i];
				masiv[i] = a;
			}
		}
		v--;
	}


}



void poisk(long double* masiv, double num, double g) {
	int left, midd, right, z, v;
	left = 0;
	right = num;
	v = 1;
	z = 0;
	while (z != 1 && fabs(v) < num)
	{
		midd = (left + right) / 2;
		if (masiv[midd] == g) {
			cout << "Число в упорядоченном массиве по возрастанию находится под индексом " << midd << endl;
			cout << "Число в упорядоченном массиве по убыванию находится под индексом " << num - midd - 1 << endl;
			z = 1;
		}
		else {
			v = v - 1;
			if (masiv[midd] < g) left = midd;
			else right = midd;
		}
	}
	if (z != 1 && num != 1) cout << "Числа нет в упорядоченных массивах\n";
	if (num == 1) cout << "Числа нет в упорядоченных массивах\n";
}
void del(long double* masiv) {
	delete[]masiv;
}