#include <iostream>
using namespace std;

class basic {
protected:
	string brand;
	string name;
	double cost;
public:
	basic(string b,string n, double c) {
		brand = b;
		name = n;
		cost = c;
	}
	basic() {
		brand = "";
		name = "";
		cost = 0;
	}
	string getBrand() {
		return brand;
	}
	string getName() {
		return name;
	}
	double getCost() {
		return cost;
	}
};
class proccesor : public basic {
	int cores;
	double frequency;
public:
	proccesor(string b, string n, int cor, double f, double cos) {
		brand = b;
		name = n;
		cost = cos;
		cores = cor;
		frequency = f;
	}
	proccesor() {
		brand = "";
		name = "";
		cost = 0;
		cores = 0;
		frequency = 0;
	}
	int getCores() {
		return cores;
	}
	double getFrequency() {
		return frequency;
	}
	friend ostream& operator<<(ostream& out, proccesor pc) {
		out << pc.brand << " " << pc.name << " " << pc.cores << " cores " << pc.frequency << "MHz " << pc.cost << "$" << endl;
		return out;
	}
};
class videocard : public basic {
	double memory;
	int type;
public:
	videocard(string b, string n, double m, int t, double cos) {
		brand = b;
		name = n;
		cost = cos;
		memory = m;
		type = t;
	}
	videocard() {
		brand = "";
		name = "";
		cost = 0;
		memory = 0;
		type = 0;
	}
	double getMemory() {
		return memory;
	}
	int getType() {
		return type;
	}
	friend ostream& operator<<(ostream& out, videocard pc) {
		out << pc.brand << " " << pc.name << " " << pc.memory << "Gb " << pc.type << " bit " << pc.cost << "$" << endl;
		return out;
	}
};
class Mem : public basic {
	double memory;
	double frequency;
public:
	Mem(string b, string n, double m, double f, double cos) {
		brand = b;
		name = n;
		cost = cos;
		memory = m;
		frequency = f;
	}
	Mem() {
		brand = "";
		name = "";
		cost = 0;
		memory = 0;
		frequency = 0;
	}
	double getMemory() {
		return memory;
	}
	double getFrequency() {
		return frequency;
	}
	friend ostream& operator<<(ostream& out, Mem pc) {
		out << pc.brand << " " << pc.name << " " << pc.memory << "Gb " << pc.frequency << "MHz " << pc.cost << "$" << endl;
		return out;
	}
};

class PC {
	proccesor proc;
	videocard card;
	Mem mem;
	double cost;
public:
	PC(proccesor p, videocard c, Mem m) {
		proc = p;
		card = c;
		mem = m;
		cost = p.getCost() + c.getCost() + m.getCost();
	}
	PC() {
		proccesor p;
		videocard c; 
		Mem m;
		proc = p;
		card = c;
		mem = m;
		cost = p.getCost() + c.getCost() + m.getCost();
	}
	proccesor getCPU() {
		return proc;
	}
	videocard getVideocard() {
		return card;
	}
	Mem getMemecard() {
		return mem;
	}
	double getCost() {
		return cost;
	}
	friend ostream& operator<<(ostream& out, PC pc) {
		out << "CPU " <<  pc.proc << "Video card " << pc.card << "Memory card " << pc.mem << "Cost " << pc.cost << "$" << endl;
		return out;
	}
};
