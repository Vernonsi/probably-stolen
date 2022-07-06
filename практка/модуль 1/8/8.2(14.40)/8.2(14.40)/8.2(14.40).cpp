#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main() {
	setlocale(0, "Ru");
	ifstream fout("Text1.txt");
	ofstream fin("Text2.txt");
	vector<string> text;
	string t;
	while (!fout.eof()) {
		fout >> t;
		text.push_back(t);

	}
	vector<string> ::iterator iter = text.begin();
	while (iter != text.end())
	{
		fin << *iter << " ";
		iter++;
	}
}