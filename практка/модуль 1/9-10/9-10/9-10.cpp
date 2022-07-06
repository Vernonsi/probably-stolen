#include <iostream>
#include <vector>
#include <fstream>
#include "Components.h"
using namespace std;

vector<PC> initialize() {
ifstream file("Text.txt");
vector<PC> computers;
string brand = "", name = "";
double cost = 0, frequency = 0, memory = 0;
int type = 0, cores = 0;
while (!file.eof()) {
	file >> brand >> name >> cores >> frequency >> cost;
	proccesor proc(brand, name, cores, frequency, cost);
	file >> brand >> name >> memory >> type >> cost;
	videocard card(brand, name, memory, type, cost);
	file >> brand >> name >> memory >> frequency >> cost;
	Mem mem(brand, name, memory, frequency, cost);
	PC pc(proc, card, mem);
	computers.push_back(pc);
}
return computers;
}




int main() {
	
	vector<PC> computers = initialize();
	vector<PC> ::iterator iter = computers.begin();
	int i = 0, maxi = 0;;
	double maxf = computers[i].getCPU().getFrequency();
	while (iter!=computers.end())
	{
		if (computers[i].getCPU().getFrequency() > maxf) {
			maxf = computers[i].getCPU().getFrequency();
			maxi = i;
		}
		cout << "\nPC\n";
		cout << *iter;
		iter++;
		i++;
	}

	cout << "\n\n\nPC with highest CPU frequency\n" << computers[maxi];
}