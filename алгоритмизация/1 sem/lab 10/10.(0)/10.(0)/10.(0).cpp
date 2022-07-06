#include <iostream>
#include <Windows.h>
using namespace std;

//4.	Аптечный СКЛАД : наименование ЛЕКАРСТВА, количество упаковок, количество таблеток в упаковке, масса таблетки.
//Упорядочьте по возрастанию имеющегося количества упаковок.Выведите информацию об указанном лекарстве.

struct drug {
	char name[255];
	int amount_drug;
	int amount_pill;
	double mass;
};

#define MAX_DRUGS 30
struct pharmacy {
	int amount;
	drug meds[MAX_DRUGS];
};

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
	cout << endl << "Количество таблеток в упаковке " <<meds.amount_pill;
	cout << endl << "Масса таблетки " << meds.mass <<endl;
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