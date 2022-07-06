#include <iostream>
#include <vector>
using namespace std;

int main() {
	setlocale(0, "Ru");
	vector<int> array;
	int i = 1;
	do {
		cin >> i;
		array.push_back(i);
	} while (i >= 0);
	vector<int> ::iterator iter = array.begin(), cmp = array.begin();
	while (iter != array.end()) {
		if (fabs(*iter) != fabs(*cmp)) {
			cout << "Элементы последовательности не равны";
			return 0;
		}
		iter++;
	}
	cout << "Элементы последовательности равны";
}