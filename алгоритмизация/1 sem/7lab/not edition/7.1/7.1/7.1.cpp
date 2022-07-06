#include <iostream>
using namespace std;
int nach() {
	setlocale(0, "Russian");
	int  num, i, a, v, No2, vibor;
	cout << "введите N" << endl;
	cin >> num;
	v = num;
	No2 = num;
	int* d = new int[num];
	//int* g = new int[No2];
	for (i = 0; i < num; i++) {
		cin >> d[i];
		//g[i] = d[i];
	}
	for (i = 0; i < num; i++) cout << d[i] << " ";
}
int vozr()
{
	int  num, i, a, v, No2;
	int* d = new int[num];
	while (v != 0) {
		for (i = 1; i < num; i++) {
			if (d[i] < d[i - 1]) {
				a = d[i - 1];
				d[i - 1] = d[i];
				d[i] = a;
			}
		}
		v--;
	}
	cout << endl << "Po vozrastaniy" << endl;
	for (i = 0; i < num; i++) cout << d[i] << " ";
}

int yb()
{
	int  num, i, a, v, No2;
	int* d = new int[num];
	while (v != 0) {
		for (i = 1; i < num; i++) {
			if (d[i - 1] < d[i]) {
				a = d[i - 1];
				d[i - 1] = d[i];
				d[i] = a;
			}
		}
		v--;
	}

	cout << endl << "Po ybivaniy" << endl;
	for (i = 0; i < num; i++) cout << d[i] << " ";
}
int main()
{
	//setlocale(0,"Russian");
	int  num, i, a, v, No2, vibor;
	nach()
	//cout << "введите N" << endl;
	//cin >> num;
	//v = num;
	//No2 = num;
	//int* d = new int[num];
	////int* g = new int[No2];
	//for (i = 0; i < num; i++) {
	//	cin >> d[i];
	//	//g[i] = d[i];
	//}
	for (i = 0; i < num; i++) cout << d[i] << " ";
	cout << "Для сортировки массива по возрастанию введите 1" << endl << "Для сортировки массива по убыванию введите 2" << endl;
	cin >> vibor;
	if (vibor != 1 || vibor != 2) {
		cout << " Error";
		return 1;
	}
	if (vibor == 1) vozr();
	if (vibor == 2) yb();
	/*while (v != 0) {
		for (i = 1; i < num; i++) {                                         
			if (d[i]<d[i-1]) {                                                             
					a = d[i - 1];                                            
					d[i - 1] = d[i];                                        
					d[i] = a;                                               
			}
		}
		v--; 
	}
	cout << endl<< "Po vozrastaniy" << endl;
	for (i = 0; i < num; i++) cout << d[i] << " ";*/

	/*while (v != 0) {
		for (i = 1; i < num; i++) {
			if (d[i-1] < d[i]) {
				a = d[i - 1];
				d[i - 1] = d[i];
				d[i] = a;
			}
		}
		v--;
	}

	cout << endl << "Po ybivaniy" << endl;
	for (i = 0; i < num; i++) cout << d[i] << " ";*/
}
//int vozr()
//{
//	int  num, i, a, v, No2;
//	int* d = new int[num];
//	while (v != 0) {
//		for (i = 1; i < num; i++) {
//			if (d[i] < d[i - 1]) {
//				a = d[i - 1];
//				d[i - 1] = d[i];
//				d[i] = a;
//			}
//		}
//		v--;
//	}
//	cout << endl << "Po vozrastaniy" << endl;
//	for (i = 0; i < num; i++) cout << d[i] << " ";
//}
//
//int yb()
//{
//	int  num, i, a, v, No2;
//	int* d = new int[num];
//	while (v != 0) {
//		for (i = 1; i < num; i++) {
//			if (d[i - 1] < d[i]) {
//				a = d[i - 1];
//				d[i - 1] = d[i];
//				d[i] = a;
//			}
//		}
//		v--;
//	}
//
//	cout << endl << "Po ybivaniy" << endl;
//	for (i = 0; i < num; i++) cout << d[i] << " ";
//}