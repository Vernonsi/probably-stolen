#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main() {
	setlocale(0, "Ru");
	ifstream file("Text.txt");
	vector<string> text;
	string t;
	while (!file.eof()) {
		file >> t;
		text.push_back(t);
		
	}
	vector<string> ::iterator iter = text.begin();
	int i = 0;
	while (iter != text.end())
	{	if(text[i][0]=='к') text[i][0] = 'К' ;
			cout << *iter << " ";
		iter++;
		i++;
	}
}