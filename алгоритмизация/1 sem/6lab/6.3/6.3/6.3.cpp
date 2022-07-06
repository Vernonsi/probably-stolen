
#include <iostream>
using namespace std;
int main()
{
	int  num, i, a, v;
	cout << "vvedite N" << endl;
	cin >> num;
	v = num;
	int *d = new int[num];
	for (i = 0; i < num; i++) {
		cin >> d[i];
	}
	for (i = 0; i < num; i++) cout << d[i] << " ";     
	while (v != 0) {
		for (i = 0; i < num; i++) {                                         //
			if (d[i] % 2 == 0) { // четное                                  //
				if (i > 0 && d[i - 1] % 2 == 1) {                            //
					a = d[i - 1];                                             // меняется
					d[i - 1] = d[i];                                        //
					d[i] = a;                                               //
				}
			}
		}
		v--; // делаем цикл столько раз, сколько в нем элементов
	}
	cout << endl;
	for (i = 0; i < num; i++) cout << d[i] << " ";
}

