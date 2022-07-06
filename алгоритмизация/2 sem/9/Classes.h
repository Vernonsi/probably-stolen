#ifndef CLASSES_H
#define CLASSES_H
#include "C:\Users\Solarte\Desktop\алгоритмизация\2 sem\Check\Check.cpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include <fstream>
using namespace std;

class Sweet {
protected:
	string name;
	double Weight;
	double sugaPer;
public:
	string getName() {
		return this->name;
	}
	void SetName(string na) {
		this->name = na;
	}
	double getWeight() {
		return this->Weight;
	}
	void SetWeight(double vei) {
		this->Weight = vei;
	}

	virtual void out() = 0;

	double getSugaPer() {
		return this->sugaPer;
	}
	void SetSugaPer(double per) {
		this->sugaPer = per;
	}
	
};


class Type : public Sweet {
	string typenames;
public:
	Type(string name, double pers, double Weight,string types) {
		this->name = name;
		this->sugaPer = pers;
		this->Weight = Weight;
		this->typenames = types;
	}
	void out() override {
		cout << typenames << endl;
		cout << "Name: " << name << " ";
		cout << "Weight: " << Weight << " ";
		cout << "Sugar Percent: " << sugaPer << endl;
	}
};


class Gift {
	double Weight = 0;
	vector<Sweet*> stack;
public:
	Gift(const char* nam) {
		fstream file(nam);
		while (!file.eof()) {
			string s1;
			file >> s1;
			string s;
			file >> s;
			int d1 = 0;
			int d2 = 0;
			file >> d1;
			file >> d2;
			Type* a = new Type(s, d1, d2, s1);
			stack.push_back(a);

		}
		Weight = WeightSum(stack);
	}

	vector<Sweet*> getStack() {
		return stack;
	}
	double getWeight() {
		return Weight;
	}
	void Outer() {
		cout << "Weight: " << Weight << endl;
		for (int i = 0; i < stack.size(); i++) {
			stack[i]->out();
		}
		for (int i = 0; i < 40; i++) {
			cout << "-";
		}
		cout << endl;
	}
	void Sort() {
		for (int i = 1; i < stack.size(); i++) {
			for (int j = i; j > 0; j--) {
				if (stack[j]->getWeight() > stack[j - 1]->getWeight()) {
					swap(stack[j], stack[j - 1]);
				}
			}
		}
	}
	
	void Search() {
		double LowP;
		double UpP;
		while (true) {
			LowP = CheckDPosit("lower value");
			UpP = CheckDPosit("upper value");
			if (LowP <= 100 && UpP <= 100 && LowP <= UpP) {
				break;
			}
			cout << "invalid input" << endl;
		}
		for (int i = 0; i < stack.size(); i++) {
			if (stack[i]->getSugaPer() >= LowP && stack[i]->getSugaPer() <= UpP) {
				stack[i]->out();
			}
		}
	}

	static double WeightSum(vector<Sweet*> vec) {
		double sum = 0;
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i]->getWeight() << "  ";
			sum += vec[i]->getWeight();
		}
		return sum;
	}



	~Gift() {
		for (int i = 0; i < stack.size(); i++) {
			delete stack[i];
		}
	}
};

#endif // CLASSES_H