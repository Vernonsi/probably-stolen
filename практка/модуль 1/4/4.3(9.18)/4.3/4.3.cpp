#include <iostream>
#include <string>
using namespace std;

int main() {
	string word1,word2;
	cin >> word1 >> word2;
	string::iterator iter1 = word1.begin(), iter2 = word2.end();
	iter2--;
	if (*iter1==*iter2) cout << "yea";
	else cout << "no";
}