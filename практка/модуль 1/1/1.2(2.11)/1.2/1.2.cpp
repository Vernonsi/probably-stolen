#include <iostream>
using namespace std;

int main() {
	setlocale(0, "Russian");
	int initial, processed;
	cout << "Введите двузначное число\n";
	cin >> initial;
	if (fabs(initial) < 10 || fabs(initial)>99) {
		cout << "Не двузначное число\n";
		return 1;
	}
	int tens, ones;
	tens = initial / 10;
	ones = initial % 10;
	processed = ones * 10 + tens;
	cout << endl << processed;
}