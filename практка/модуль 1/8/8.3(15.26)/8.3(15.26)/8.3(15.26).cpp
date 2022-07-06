#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main() {
	setlocale(0, "Ru");
	ifstream fout("Text1.txt");
	ofstream fin("Text2.txt");
	vector<char> text;
	char t;
	while (!fout.eof()) {
		fout.get(t);
		text.push_back(t);

	}

	vector<char> ::iterator iter = text.begin();
	while (iter != text.end())
	{
		if (*iter == '\n' && iter!=text.end()-1) fin << "!";
		fin << *iter;		
		iter++;
	}
	// тут нет вывода, потому что нам надо перекинуть из одного файла в другой, а это можно посмотреть В ФАЙЛЕ [УДАЛЕНО](здесь были маты)
}