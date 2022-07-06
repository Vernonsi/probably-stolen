#include <iostream>
#include <string>
using namespace std;

int main() {
	int N1, N2;
	string S1, S2,S3;
	cin >> S1 >> S2;
	cin >> N1 >> N2;
	if (S1.length() < N1 || S2.length() < N2) {
		cout << "invalid values";
		return 1;
	}
	for (int i = 0; i < N1; i++) {
		S3.push_back(S1.at(i));
	}
	
	for (int i = S2.length()-N2; i < S2.length(); i++) {
		S3.push_back(S2.at(i));
	}
	cout << S3;
	return 0;
}