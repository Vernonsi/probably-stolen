#include <iostream>
using namespace std;

int main()
{
	double a, b,c,p,s;
	cin >> a>>b>>c;
	p = (a + b + c) / 2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	cout << s;
	system("pause");
	return 0;
}