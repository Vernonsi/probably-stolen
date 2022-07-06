#include <iostream>
#include <vector>
#include "Train.h"


using namespace std;

void InitMass(vector<Train>* array, int size) {
	for (int i = 0; i < size; i++) {
		Train t;
		t.init();
		array->push_back(t);
	}
}

void OutMass(vector<Train> array) {
	for (vector<Train>::iterator i = array.begin(); i != array.end(); i++) {
		(*i).out();
	}
}

int main()
{
	int size = initsize();
	vector<Train> routes;
	InitMass(&routes, size);
	Sort(&routes);
	OutMass(routes);
	stationc(routes);


}