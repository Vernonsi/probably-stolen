#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cout << "type length\n";
	cin >> n;
	vector<double> h1(n);
	for (int i = 0; i < n; i++) {
		cin >> h1[i];
	}
	cout << endl << endl;
	vector<double> h2;
	for (int i = 0; i < n; i++) {
		if (h1[i] < 0) {
			h2.push_back(h1[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (h1[i] == 0) {
			h2.push_back(h1[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (h1[i] > 0) {
			h2.push_back(h1[i]);
		}
	}
	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		cout << h2[i] << " ";
	}
}