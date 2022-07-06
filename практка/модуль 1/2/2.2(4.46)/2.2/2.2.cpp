#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "Ru");
	double a, b, c;
	cin >> a >> b >> c;
	if ((a == b && a != c) ||
		(a == c && a != b) ||
		(c == b && a != c))
		cout << "\nТреугольник равнобедренный";
	else cout << "\nТреугольник не равнобедренный";
}