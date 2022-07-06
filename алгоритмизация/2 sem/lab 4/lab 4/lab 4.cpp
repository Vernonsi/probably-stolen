#include<iostream>
#include "Class.h"
using namespace std;





int main() {
	int n;
	cin >> n;
	mass<int> mas(n);
	cin >> mas;
	
	mas.decend();
	cout << mas << endl;
	mas.ascend();
	cout << mas << endl;

	cin >> n;
	mass<double> gas(n);
	cin >> gas;
	gas.decend();
	cout << gas << endl;
	gas.ascend();
	cout << gas << endl;
}