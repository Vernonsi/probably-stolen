#include <iostream>
#include <Windows.h>
#include "Header.h"
using namespace std;

int main() {
	setlocale(0, "Russian");
	pharmacy bonk;
	cout << "������� ���������� ����� �������� (�� ������ 30)" << endl;
	cin >> bonk.amount;
	for (int i = 0; i < bonk.amount; i++) {
		cout << "------------------------------------------------" << endl;
		cout << "������� ���������� � " << (i + 1) << " ���������\n";
		cout << "------------------------------------------------" << endl;
		bonk.meds[i] = initialize();
	}


	cout << "------------------------------------------------" << endl;
	cout << "������� ����� ���������, ���������� � ������� ������� �������" << endl;
	int a;
	cin >> a;
	cout << "------------------------------------------------";
	if (a > 0 && a <= bonk.amount) {
		output_drug(bonk.meds[a - 1]);
	}
	else cout << "\n ������� ������ �����\n";


	insSort_ascending(bonk.meds, bonk.amount);
	cout << endl << "------------------------------------------------" << endl;
	cout << "������ ��������\n";
	cout << "------------------------------------------------" << endl;
	for (int i = 0; i < bonk.amount; i++) {
		output_drug(bonk.meds[i]);
	}
}