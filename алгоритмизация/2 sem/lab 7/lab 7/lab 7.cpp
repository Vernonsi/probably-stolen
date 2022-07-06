#include <iostream>
#include <vector>
#include <iterator>
#include <windows.h>
using namespace std;


vector<double> cinV(vector<double> v) {	
	cout << "Введите последовательность дробных чисел (конец ввода - Ctrl+Z)\n";
	// объявление итератора для чтения дробных чисел из потока (cin)
	istream_iterator<double> cin_iter(cin);
	// итератор - конец потока (любого) дробных чисел
	istream_iterator<double> cin_end;
	while (cin_iter != cin_end) { // дошли до конца потока?
		double x = *cin_iter; // взять текущий элемент из потока
		v.push_back(x); // добавить его в вектор
		cin_iter++; // перейти к следующему элементу потока
	}
	return v;
}

void coutV(vector<double> v) {
	cout << "Последовательность дробных чисел:\n";
	// объявление итератора - указателя на элемент вектора
	vector<double>::iterator iter;
	iter = v.begin(); // начинаем с начала вектора
	while (iter < v.end()) { // дошли до конца вектора?
		cout << *iter << endl; // обработка текущего элемента
		iter++; // перейти к следующему элементу вектора
	}
}

double sumV(vector<double> v) {
	vector<double>::iterator iter;
	double sum = 0;
	iter = v.begin();
	int m = 0;
	while (iter != v.end()) {
		
	if (m==1 && *iter>=0) sum = sum + *iter;
	if (*iter < 0) {
		m++;
	}
	iter++;
	}
	return sum;
}
vector<double> ascend(vector<double> b) {
	vector<double> a = b;
	vector<double>::iterator iter,it;
	iter = a.begin(); 
	cout << "\nAscending\n";
	while (iter != a.end()) {
		it = a.begin();
		while(it!=a.end()) {
			if (*iter < *it)	swap(*iter, *it);
			it++;
		}
		iter++;
	}
	return a;
}

vector<double> decend(vector<double> b) {
	vector<double> a = b;
	vector<double>::iterator iter, it;
	iter = a.begin();
	cout << "\nDecending\n";
	while (iter != a.end()) {
		it = a.begin();
		while (it != a.end()) {
			if (*iter > *it)	swap(*iter, *it);
			it++;
		}
		iter++;
	}
	return a;
}




int main(int argc, char* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<double> v;
	v=cinV(v);
	double sum=0;
	sum = sumV(v);	
	cout << "\n\nСумма между первым и вторым отрицательным элементом\n" << sum << endl;
	vector<double> dc = decend(v);
	coutV(dc);
	vector<double> ac = ascend(v);
	coutV(ac);
	system("pause");
	return 0;
}