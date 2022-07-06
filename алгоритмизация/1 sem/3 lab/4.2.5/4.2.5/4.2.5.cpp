#include <iostream>
using namespace std;

int main()
{ setlocale(0, "Russian");
	double a, b, c, p, s;
	cin >> a >> b >> c;
	if ((a <= 0) || (b <= 0) || (c <= 0))
	{
		cout << "Введите натуральные числа";
		return 0;
	}
	p = (a + b + c) / 2;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	cout << s;
	system("pause");
	return 0;
}