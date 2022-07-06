#include <iostream>
using namespace std;

int main() {
	setlocale(0, "Russian");
	
	string monthsList[12] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
	int mDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int d, m;
	cout << "Введите число и порядковый номер месяца в невисокосном году\n";
	cin >> d >> m;
	if (m > 12 || m < 1 || d < 1 || d>mDays[m - 1]) {
		cout << "Неверные значения";
		return 1;
	}

	cout << "\nСледующий день ";
	if (d == mDays[m - 1]) {
		if (m==12) cout << 1 << " " << monthsList[0];
		else
		cout << 1 << " " << monthsList[m];
	}
	else cout << d+1 << " " << monthsList[m-1];
	cout << "\nПредыдущий день ";
	if (d == 1) {
		if (m == 1) cout << mDays[11] << " " << monthsList[11];
		else
		cout << mDays[m - 2] << " " << monthsList[m - 2];
	}
	else cout << d -1 << " " << monthsList[m - 1];

}