#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

class car {
	string name;
	int cost;
	int engine;
public:
	car(string NAME, int COST, int ENGINE) {
		name = NAME;
		cost = COST;
		engine = ENGINE;
	}
	string getName() {
		return name;
	}
	int getCost() {
		return cost;
	}
	int getEngine() {
		return engine;
	}
	friend ostream& operator<<(ostream& out, car& digit) {
		out << digit.name << " " << digit.cost << " " << digit.engine << endl;
		return out;
	}
};

void generate() {
	ofstream f("Cars.txt");
	int* c = new int[30];
	int* e = new int[30];
	const char* m[] = {"BMW","Opel","Lada","Honda","Tesla","Mercedes","Wolkswagen","Toyota"};
	for (int i = 0; i < 30; i++) {
		c[i] = rand() % 200000 + 1000;
		e[i] = rand() % 120 + 20;
		f << m[rand() % 7] << " " << c[i] << " " << e[i] << endl;
	}
}


int main() {
	srand(static_cast<unsigned int>(time(0)));
	generate();
	ifstream file("Cars.txt");
	vector<car> array;
	string name;
	int cost;
	int engine;
	while (!file.eof()) {
		file >> name >> cost >> engine;
		car digit(name, cost, engine);
		array.push_back(digit);
	}
	array.erase(array.end()-1);
	vector<car> ::iterator iter = array.begin();
	int i = 0;
	while (iter!=array.end())
	{
		if(array[i].getEngine() <= 80)
		cout << *iter;
		iter++;
		i++;
	}
}