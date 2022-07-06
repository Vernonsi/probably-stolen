#include "Queue.h";

//Forming of queue
Node_q* first_q(double d) {
	Node_q* pv = new Node_q;
	pv->d = d;
	pv->p = 0;
	return pv;
}

//Adding into end of queue
void add_q(Node_q** pend, double d) {
	Node_q* pv = new Node_q;
	pv->d = d;
	pv->p = 0;
	(*pend)->p = pv;
	*pend = pv;
}

//Output of first element
double del_q(Node_q** pbeg) {
	double temp = (*pbeg)->d;
	Node_q* pv = *pbeg;
	*pbeg = (*pbeg)->p;
	delete pv;
	return temp;
}