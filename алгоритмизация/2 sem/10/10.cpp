#include <set>
#include <iostream>
#include <iterator>
#include "Classes.h"

using namespace std;

int main()
{
	set<Train*> array;
	read("data.txt", &array);
	for (auto i : array) {
		i->out();
	}
	string s;
	cout << "input number: ";
	cin >> s;
	for (auto i : array) {
		if (i->getNum() == s) {
			i->out();
		}
	}
	cout << "input station: ";
	cin >> s;
	for (auto i : array) {
		if (i->getStation() == s) {
			i->out();
		}
	}

}