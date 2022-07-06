#include <iostream>
using namespace std;

int main() {
	setlocale(0, "Ru");
	int a, b;
	cout << "Введите числа\n";
	cin >> a >> b;
	if (a == 0 || b == 0) {
		cout << "На ноль делить нельзя\n";
		return 1;
	}
	if (a % b == 0 || b % a == 0) cout << "Да, одно из чисел является делителем другого\n";
	else cout << "Нет, ни одно из чисел не является делителем другого\n";
	return 0;
}