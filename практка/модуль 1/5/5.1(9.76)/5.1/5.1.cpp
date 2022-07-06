#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(0, "Ru");
	string sentence;
	getline(cin,sentence);
	string::iterator iter = sentence.begin();
	int i = 0;
	int first,last;
	bool check = 0;
	while (iter!= sentence.end()) {
		if (sentence[i] == 'e') {
			if (!check) first = i;
			check = 1;
			last = i;
		}
		i++;
		iter++;
	}
	if (!check) cout << "net e";
	else cout << "first e " << first+1 << "\nlast e " << last+1;
}