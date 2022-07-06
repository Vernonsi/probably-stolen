#include <iostream>
using namespace std;
int main()
{
	int  num, i, a, v, g;
	cout << "vvedite N" << endl;
	cin >> num;
	v = num;
	g = 1;
	int i2 = -1;
	int i3 = -1;
	int num2 = num / 2;
	int num3 = num - num2;
	if (num % 2 == 0) {
		num2 = num2 - 1;
		num3 = num3 + 1;
	}
	long int* d2 = new long int[num2];
	long int* d3 = new long int[num3];
	long int* d = new long int[num];
	for (i = 0; i < num; i++) {
		cin >> d[i];
	}
	/*cout << "\n ch" << num2;
	cout << "\n nech" << num3 << endl;*/
	for (i = 0; i < num; i++) {
		if (i % 2 == 0 && i != 0) {
			i2++;
			d2[i2] = d[i];

		}
	}
	for (i = 0; i < num; i++) {
		if (i % 2 == 1 || i == 0) {
			i3++;
			d3[i3] = d[i];

		}
	}
	for (i = 0; i < num; i++) cout << d[i] << " ";

	cout << endl;

	for (i2 = 0; i2 < num2; i2++) cout << d2[i2] << " ";
	cout <<"Even index" <<endl;
	for (i3 = 0; i3 < num3; i3++) cout << d3[i3] << " ";
	cout <<"Odd index + 0 "<< endl;

	for (i = 0, i2 = 0, i3 = -1; i < num; i++, i2++) {
		if (i < num2) d[i] = d2[i2];
		else {
			i3++;
			d[i] = d3[i3];
		}
		cout << d[i] << " ";

	}
}

