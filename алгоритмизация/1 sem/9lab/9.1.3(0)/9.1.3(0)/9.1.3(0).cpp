#include <iostream>
#include <string.h>
using namespace std;

//void ncat(char* a,char* b,int s) {
//	strncat_s(a, b, s);
//	cout << a;
//}

int main() {
	setlocale(0, "Russian");
	char a[255], b[255];
	int i,k,s;
	cout << "Введите первую строку\n";
	cin.getline(a, 255);
	cout << "Введите вторую строку\n";
	cin.getline(b, 255);
	cout << "Введите количество добавляемых символов\n";
	cin >> s;
	/*ncat(a,b,s);*/
	for (int i = 0; a[i] != '\0'; i++)  //размер первой
	{
		k = i + 1;
	}
	for (int i = 0; i<s; k++, i++)
	{
		a[k] = b[i]; 
	}
	a[k] = '\0';  
	cout << a << endl;
	return 0;
}