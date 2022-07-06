#include <iostream>
#include <string.h>
using namespace std;

int siz(char* a) {
	int k;
	for (int i = 0; a[i] != '\0'; i++) 
	{
		k = i + 1;
	}
	return k;
}

void sravn(char*a,char*b,int size_a, int size_b) {
	int same = 1;
	for (int i = 0; i < size_b; i++)
	{
		if (a[same] == b[i]) {
			same = same + 1;
		}
	}
	if (same >= size_a) cout << "можно";
	else cout << "нельзя";
}

int main() {
	setlocale(0, "Russian");
	char a[255], b[255];
	int i, k, s;
	cout << "Введите первое слово\n";
	cin >> a;
	cout << "Введите второе слово\n";
	cin >> b;
	int a_s=siz(a);
	int b_s = siz(b);
	cout << endl << "Первое слово ";
	sravn(a, b, a_s,b_s);
	cout << " получить из второго методом вычеркивания";
	cout << endl << "Второе слово ";
	sravn(b, a, b_s, a_s);
	cout << " получить из первого методом вычеркивания\n";
	return 0;
}