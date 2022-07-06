#include <iostream>
#include <Windows.h>
#include "Header.h"
using namespace std;

int main() {
	setlocale(0, "Russian");
	pharmacy bonk;
	cout << "Введите количество видов лекарств (не больше 30)" << endl;
	cin >> bonk.amount;
	for (int i = 0; i < bonk.amount; i++) {
		cout << "------------------------------------------------" << endl;
		cout << "Введите информацию о " << (i + 1) << " лекарстве\n";
		cout << "------------------------------------------------" << endl;
		bonk.meds[i] = initialize();
	}


	cout << "------------------------------------------------" << endl;
	cout << "Введите номер лекарства, информацию о котором следует вывести" << endl;
	int a;
	cin >> a;
	cout << "------------------------------------------------";
	if (a > 0 && a <= bonk.amount) {
		output_drug(bonk.meds[a - 1]);
	}
	else cout << "\n Неверно введен номер\n";


	insSort_ascending(bonk.meds, bonk.amount);
	cout << endl << "------------------------------------------------" << endl;
	cout << "Список лекарств\n";
	cout << "------------------------------------------------" << endl;
	for (int i = 0; i < bonk.amount; i++) {
		output_drug(bonk.meds[i]);
	}
}