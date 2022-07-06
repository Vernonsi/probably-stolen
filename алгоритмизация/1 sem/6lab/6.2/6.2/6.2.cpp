
#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "Russian");
	int  num, i, max, a,min,gran1,gran2,pr;
	cout << "введите N" << endl;
	cin >> num;
	pr = 1;
	max = 0;
	int* d = new int[num];
	for (i = 0; i < num; i++) {
		cin >> d[i];
		if (max <= abs(d[i])) {
			max = abs(d[i]);
			gran1 = i;
		}
	}
	min = max;
	for (i = 0; i < num; i++) {
		if (min > abs(d[i])) {
			min = abs(d[i]);
			gran2 = i;
		}
	} 
	if (min == max) {
		cout << "Элементы массива равны";
		return 0;
	}
	if (fabs(fabs(gran1) - fabs(gran2)) == 1) {
		cout << "между Min и Max нет элементов";
		return 0;
	}
	if (gran1 > gran2) {
		for (i = gran2+1; i < gran1; i++) pr= pr * d[i];
	}
	else for (i = gran1+1; i < gran2; i++) pr = pr * d[i];
	cout <<endl << pr << endl;

	
	} 
