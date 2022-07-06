#include <iostream>
#include <fstream>
#include <stdio.h>
#include "train.h"
using namespace std;

#define MAX 30

int main()
{
    int size;
	route* Trains[MAX];
    try {
        read("data.txt", Trains, size);
        Output(Trains, size);
        Sort(Trains, size);
        cout << endl;
        Output(Trains, size);
       // stationc("love", Trains, size);
    }
    catch (const char* error) {
        cout << error << '\n';
    }
}
