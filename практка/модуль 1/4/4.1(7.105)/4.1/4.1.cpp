#include <iostream>
using namespace std;

int main() {
	setlocale(0, "Ru");
	int n;
	cout << "Введите размер массива\n";
	cin >> n;
	cout << "Введите элементы массива\n";
	int* array = new int[n];
	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> array[i];
		if (array[i] < 0) count++;
	}
	cout << "Введите Х\n";
	int x;
	cin >> x;
	if (x != count) {
		if (x > count) cout << "Х больше количества отрицательных элементов массива";
		else cout << "Х меньше количества отрицательных элементов массива";
	}
	else cout << "Х равно количеству отрицательных элементов массива";
	return 0;
}