#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "Ru");
	int year;
	cin >> year;
	if (year % 4 == 0) {
		if (year % 100 == 0 && year % 400 != 0)	
	cout << "\nНе Високосный " << "365 дней";
		else 
			cout << "\nВисокосный " << "366 дней";
	}
	else 
		cout << "\nНе Високосный " << "365 дней";
}