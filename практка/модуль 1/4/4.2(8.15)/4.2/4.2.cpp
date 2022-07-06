#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main() {
	srand(static_cast<unsigned int>(time(0)));
	setlocale(0, "Ru");
	int** sportsman = new int* [8];
	for (int i = 0; i < 8; i++) {
		sportsman[i] = new int[5];
	}
	int* sum = new int[8];
	for (int i = 0; i < 8; i++) {
		sum[i] = 0;
		for (int j = 0; j < 5; j++) {
			cout << "Введите баллы спортсмена №" << i + 1 << " по спорту №" << j + 1 << endl;
			sportsman[i][j] = rand() % 20;
			cout << sportsman[i][j] << endl;
			sum[i]+= sportsman[i][j];
		}
	}
	int j = 0;
	cout << "\n\n Спортсмен" << setw(30) << "Спорт\n" << "    ";
	for (int j = 0; j < 5; j++) {
		cout << setw(10) << j + 1;
	}
	cout << endl;
	for (int i = 0; i < 54; i++) cout << "_";
	cout << endl;
	for (int i = 0; i < 8; i++) {
		cout << " " << i + 1 << " |" ;
		for (int j = 0; j < 5; j++) {
			cout << setw(10) << sportsman[i][j];
		}
		cout << endl;
	}
	int max = sportsman[0][0];
	int maxsum = sum[0];
	int i_maxsum = 0;
	for (int i = 0; i < 8; i++) {
		if (maxsum < sum[i]) {
			maxsum = sum[i];
			i_maxsum = i;
		}
		for (int j = 0; j < 5; j++) {
			if (max < sportsman[i][j]) max = sportsman[i][j];
		}
	}
	cout << "\nПобедитель с номером " << i_maxsum+1 << " набрал " << maxsum << " баллов\nМаксимальный балл " << max;


	return 0;
}