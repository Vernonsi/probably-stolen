#include <iostream>
using namespace std;

int main() {
	setlocale(0, "Russian");
	int n, x;
	cout << "Введите число\n";
	cin >> n;
	if (n <= 1 || n >= 999) {
		cout << "Число вне диапазона (1<=n<=999)\n";
		return 1;
	}
	int hundreds, tens;
	hundreds = (n % 100) % 10;
	tens = n / 10;
	x = hundreds * 100 + tens;
	cout << endl << x;
}