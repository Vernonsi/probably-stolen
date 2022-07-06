#include <iostream>
using namespace std;

int Euclid(int a,int b) {
	
	NOD:
	if (a == b) return a;
	if (a > b) a = a - b;
	else b = b - a;
	goto NOD;
}

int main() {
	setlocale(0, "Ru");
	int a, b;
	cin >> a >> b;
	if (b == 0) {
		cout << "На ноль делить нельзя\n";
		return 1;
	}
	if (a == 0) {
		cout << "Ноль при делении равен нулю\n";
		return 1;
	}
	cout << endl << endl << a << "/" << b <<" = " << a/Euclid(a,b) <<"/" <<b/Euclid(a,b);
	
}