
#include <iostream>
using namespace std;
int main()
{ 
	int  num,i,max,a;
	cout << "vvedite N" << endl;
	cin >> num;
	max = 0;
	int* d = new int[num];
	for (i = 0; i < num; i++) {
		cin >> d[i];
		if (max < abs(d[i])) max = abs(d[i]);
	}
	cout << endl <<"Max modul " << max;
}

