#include <iostream>

struct Node_s {
	double d;
	Node_s* p;
};

Node_s* first_s(double d);
void push_s(Node_s** top, double d);
double pop_s(Node_s** top);