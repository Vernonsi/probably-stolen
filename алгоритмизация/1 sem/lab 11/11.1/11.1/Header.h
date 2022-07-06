#include <iostream>
#include <Windows.h>

struct drug {
	char name[255];
	int amount_drug;
	int amount_pill;
	double mass;
};

#define MAX_DRUGS 30
struct pharmacy {
	int amount;
	drug meds[MAX_DRUGS];
};

drug initialize();
void output_drug(drug meds);
void insSort_ascending(drug* arrayPtr, double array_size);

