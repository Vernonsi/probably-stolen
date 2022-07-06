#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(0, "Ru");
	string word1, word2;
	cin >> word1 >> word2;
	string::iterator iter1 = word1.begin(), iter2;
	while (iter1 != word1.end()) {
		iter2 = word2.begin();
		bool check = 0;
		while (iter2 != word2.end()) {
			if (*iter1 == *iter2) check = 1;
			iter2++;
		}
		if (check) cout << "да ";
		else cout << "нет ";
		iter1++;
	}
}