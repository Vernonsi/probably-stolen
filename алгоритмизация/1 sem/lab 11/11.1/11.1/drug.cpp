#include <iostream>
#include <Windows.h>
#include "Header.h"
using namespace std;

drug initialize() {
	drug meds;
	cout << "Введите название лекарства\n";
	cin >> meds.name;
	cout << "Введите количество упаковок\n";
	cin >> meds.amount_drug;
	cout << "Введите количество таблеток в упаковке\n";
	cin >> meds.amount_pill;
	cout << "Введите массу таблетки\n";
	cin >> meds.mass;
	return meds;
}

void output_drug(drug meds) {
	cout << endl << "Название " << meds.name;
	cout << endl << "Количество упаковок " << meds.amount_drug;
	cout << endl << "Количество таблеток в упаковке " << meds.amount_pill;
	cout << endl << "Масса таблетки " << meds.mass << endl;
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
