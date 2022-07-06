#include "Header.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(0, "Russian");
	char* num = new char[255];
	cout << "¬ведите размер массива" << endl;
	cin >> num;
	double k = atof(num);
	if (num == to_string((int)atof(num)) && k >= 1 && k - int(k) == 0) {
		long double* masiv = new long double[k];
		long double* masiv_1 = new long double[k];
		vvod(masiv, masiv_1, k);
		vivod(masiv, k);
		vozr(masiv, k);
		yb(masiv_1, k);
		cout << endl << "—ортировка по возрастанию";
		vivod(masiv, k);
		cout << endl << "—ортировка по убыванию";
		vivod(masiv_1, k);
		cout << "\n¬ведите действительное число\n";
		double g;
		cin >> g;
		poisk(masiv, k, g);
		del(masiv);
		del(masiv_1);
	}
	else  cout << "Error";


}