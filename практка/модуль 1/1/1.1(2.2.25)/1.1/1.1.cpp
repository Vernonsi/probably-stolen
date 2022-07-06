#include <iostream>
using namespace std;

int main() {
	setlocale(0, "Russian");
	int* array = new int [180];
	int tens, ones;
	for (int j = 0, i = 10; i < 100; j++, i++) {
		tens = i / 10;
		ones = i % 10;
		array[j] = tens;
		cout << array[j];
		j++;
		array[j] = ones;
		cout << array[j];
	}
	int K;
	cout << endl << "Введите целое число К от 1 до 180\n";
	cin >> K;
	cout << "\nЦифра в " << K << "-й позиции: " << array[K-1];
	
}