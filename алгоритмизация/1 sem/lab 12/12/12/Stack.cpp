#include "Stack.h"

//Forming of stack
Node_s* first_s(double d) {
	Node_s* pv = new Node_s;
	pv->d = d;
	pv->p = 0;
	return pv;
}

//Pushing into stack
void push_s(Node_s** top, double d) {
	Node_s* pv = new Node_s;
	pv->d = d;
	pv->p = *top;
	*top = pv;
}

//Pop out
double pop_s(Node_s** top) {
	double temp = (*top)->d;
	Node_s* pv = *top;
	*top = (*top)->p;
	delete pv;
	return temp;
}