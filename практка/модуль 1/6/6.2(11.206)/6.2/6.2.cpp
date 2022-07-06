#include <iostream>
using namespace std;

bool check(int element, int size) {
	if (element > size || element <= 0)
		return false;
	return true;
}

int main() {
	int n;
	cout << "size\n";
	cin >> n;
	int* array = new int[n];
	cout << "elements\n";
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	int j = -1;
	for (int i = 0; i < n-1; i++) {
		if (array[i] % 2 == 0 && array[i + 1] % 2 == 0 && array[i]!=0 && array[i+1]!=0) j = i;
	}
	if (j >= 0)
		for (int i = 0; i < j; i++) {
			cout << array[i] << " ";
		}
	else cout << "no pairs";
}