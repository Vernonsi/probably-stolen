#include <iostream>
using namespace std;

bool check(int element,int size) {
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
	int s, k;
	cout << "s-?\n";
	cin >> s;
	cout << "k-?\n";
	cin >> k;
	if (!check(s, n) || !check(k, n)) {
		cout << "invalid arguments\n";
		return 1;
	}
	
	if (array[s - 1] == 0) cout << "s element is zero\n" << array[k - 1] << endl;
	else {
		if (array[s - 1] > 0) cout << "s element is positive\n" << array[s - 1] << endl;
		else cout << "s element is negative\n" << array[s - 1] << endl;
	}

	if (array[k-1]==0) cout << "k element is zero\n" << array[k - 1] << endl;
	else {
		if (array[k - 1] % 2 == 0) cout << "k element is even\n" << array[k - 1] << endl;
		else cout << "k element is odd\n" << array[k - 1] << endl;
	}

	if (array[s - 1] != array[k - 1]) {
		if (array[s - 1] > array[k - 1]) cout << "s element > k element\n" << array[s - 1] << " > " << array[k - 1] << endl;
		else cout << "s element < k element\n" << array[s - 1] << " < " << array[k - 1] << endl;
	}
	else cout << "s element = k element\n" << array[s - 1] << " = " << array[k - 1] << endl;
}