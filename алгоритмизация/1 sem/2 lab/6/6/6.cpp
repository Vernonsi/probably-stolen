#include <iostream>
using namespace std;

int main()
{
	double ab,ac,bc,xa,xb,ya,yb,xc,yc,P;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	ab = sqrt((pow((xa - xb), 2) + (pow((ya - yb), 2))));
	ac = sqrt((pow((xa - xc), 2) + (pow((ya - yc), 2))));
	bc = sqrt((pow((xb - xc), 2) + (pow((yb - yc), 2))));
	P = ab + bc + ac;
	cout << P;
	return 0;
}