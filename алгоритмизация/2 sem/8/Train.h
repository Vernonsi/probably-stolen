#ifndef TRAIN_H
#define TRAIN_H
#include <vector>
#include <iostream>

int initsize();


using namespace std;
class Times {
	int hour;
	int min;
	int sec;
public:
	Times();
	Times(int h, int m, int s);
	int getH();
	int getM();
	int getS();
	bool timesr(Times t2);
	void out();
	 Times timein();
};

class Train {
	string number;
	string destination;
	Times start;
	Times end;
public:
	Train();
	Train(string num, string dest, Times start, Times end);
	string getNumber();
	string getDest();
	Times getSt();
	Times getEn();
	void out();
	void init();

};

int timeres(Times t);
void Sort(vector<Train>* array);
void stationc(vector<Train> array);

#endif // !TRAIN_H
