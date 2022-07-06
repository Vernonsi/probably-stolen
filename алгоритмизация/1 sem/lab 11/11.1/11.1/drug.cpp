#include <iostream>
#include <Windows.h>
#include "Header.h"
using namespace std;

drug initialize() {
	drug meds;
	cout << "������� �������� ���������\n";
	cin >> meds.name;
	cout << "������� ���������� ��������\n";
	cin >> meds.amount_drug;
	cout << "������� ���������� �������� � ��������\n";
	cin >> meds.amount_pill;
	cout << "������� ����� ��������\n";
	cin >> meds.mass;
	return meds;
}

void output_drug(drug meds) {
	cout << endl << "�������� " << meds.name;
	cout << endl << "���������� �������� " << meds.amount_drug;
	cout << endl << "���������� �������� � �������� " << meds.amount_pill;
	cout << endl << "����� �������� " << meds.mass << endl;
}

void insSort_ascending(drug* arrayPtr, double array_size) {
	drug temp;
	int index_of_previous;
	for (int i = 1; i < array_size; i++) {
		temp = arrayPtr[i];
		index_of_previous = i - 1;
		while (index_of_previous >= 0 && (arrayPtr[index_of_previous].amount_drug) > (temp.amount_drug)) {
			arrayPtr[index_of_previous + 1] = arrayPtr[index_of_previous];
			arrayPtr[index_of_previous] = temp;
			index_of_previous--;
		}
	}
}
