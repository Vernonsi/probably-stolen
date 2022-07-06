#include <iostream>
#include <string>
using namespace std;
void vvod(long double*masiv, long double* masiv_1, double num) {
	cout << "Введите массив" << endl;
	for (int i = 0; i < num; i++) {
		cin >> masiv[i];
	
		masiv_1[i] = masiv[i];
	}

}

void vivod(long double*masiv,double num) {
	cout << endl;
	for (int i = 0; i < num; i++) cout << masiv[i]<< " ";
}

void vozr(long double* masiv, double num) {
	double a;
	double v = num;
	while (v != 0) {
		for (int i = 1; i < num; i++) {
			if (masiv[i - 1] > masiv[i]) {
				a = masiv[i - 1];
				masiv[i - 1] = masiv[i];
				masiv[i] = a;
			}
		}
		v--;
	}

}



void yb(long double* masiv, double num) {
	double a;
	double v = num;
	while (v != 0) {
		for (int i = 1; i < num; i++) {
			if (masiv[i - 1] < masiv[i]) {
				a = masiv[i - 1];
				masiv[i - 1] = masiv[i];
				masiv[i] = a;
			}
		}
		v--;
	}

	
}



void poisk_v_vozr(long double* masiv, double num, double g) {
	int left, midd, right,z,v;
	left = 0;
	right = num;
	v = 1;
	z = 0;
	while (z!=1 && fabs(v)<num)
	{midd = (left + right) / 2;
	if (masiv[midd] == g) {
		cout << "Число в упорядоченном по возрастанию массиве находится под индексом " << midd << endl;;
		z = 1;
	}
		else {
		v = v - 1;
			if (masiv[midd] < g) left = midd;
			else right = midd;
		}
	}
	if (z != 1 && num!=1) cout << "Числа нет в упорядоченном по возрастанию массиве\n";
	if (num==1) cout << "Числа нет в упорядоченном по возрастанию массиве\n";
}

void poisk_v_yb(long double* masiv, double num, double g) {
	int left, midd, right, z, v;
	left = 0;
	right = num;
	v = 1;
	z = 0;
	while (z != 1 && fabs(v) < num)
	{
		midd = (left + right) / 2;
		if (masiv[midd] == g) {
			cout << "Число в упорядоченном по убыванию массиве находится под индексом " << midd<< endl;
			z = 1;
			break;
		}
		else {
			v = v - 1;
			if( masiv[midd] > g) left = midd;
			else right = midd;
		}
	}
	if (z != 1 && num!=1) cout << "Числа нет в упорядоченном по убыванию массиве\n";	
	if (num==1) cout << "Числа нет в упорядоченном по убыванию массиве\n";
}
void del(long double*masiv) {
	delete[]masiv;
}

int main(){
	setlocale(0,"Russian");
	char* num= new char [255];
	cout << "Введите размер массива"<< endl;
	cin >> num;
	double k = atof(num);
	if (num == to_string((int)atof(num)) && k >= 1 && k - int(k) == 0) {
		long double* masiv = new long double[k];
		long double* masiv_1 = new long double[k];
		vvod(masiv,masiv_1,k);
		vivod(masiv, k);
		vozr(masiv, k);
		yb(masiv_1,k);
		cout << endl << "Сортировка по возрастанию";
		vivod(masiv, k);
		cout << endl << "Сортировка по убыванию" ;
		vivod(masiv_1, k);
		cout << "\nВведите действительное число\n";
		double g;
		cin >> g;
		poisk_v_vozr(masiv, k, g);
		poisk_v_yb(masiv_1, k, g);
		del(masiv);
		del(masiv_1);
	}
	else  cout << "Error";


}