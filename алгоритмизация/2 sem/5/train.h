#ifndef TRAIN_H
#define TRAIN_H
#include <iostream>

using namespace std;

#define MAX_STRING_SIZE 200

struct times {
	int hour;
	int min;
	int sec;
};

struct route {
	char number[MAX_STRING_SIZE];
	char destination[MAX_STRING_SIZE];
	times start;
	times end;
};

times convert(char* str);
int str(const char* name);
void read(const char* file_name, route* array[], int& size);
void Out(route* C);
long int timeres(times* t);
void Output(route* array[], int size);
void Sort(route* array[], int size);
void stationc(string str, route* array[], int size);
void stationf(const char* file_name, string str, route* array[], int size);
void fileout(const char* file_name, route* array[], int size);
ostream& operator<<(ostream& viv, route i);


#endif 