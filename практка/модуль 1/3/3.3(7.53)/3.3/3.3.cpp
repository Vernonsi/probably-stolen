#include<iostream>
using namespace std;

int main() {
	setlocale(0, "Ru");
	int n;
	cout << "Введите количество результатов\n";
	cin >> n;
	double* time = new double[n];
	cout << "Введите результаты\n";
	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}
	double min = time[0];
	for (int i = 0; i < n; i++) {
		if (min > time[i]) min = time[i];
	}
	cout << "Лучший результат: "<< min;
	
}