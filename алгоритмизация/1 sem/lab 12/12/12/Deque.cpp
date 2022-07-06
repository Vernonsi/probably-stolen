#include "Deque.h"


//initialization
Node_d* first_d(double d) {
	Node_d* pv = new Node_d;
	pv->d = d;
	pv->p = 0;
	return pv;
}


//Adding into top of deque
void addFirst_d(Node_d** pbeg, double d) {
	Node_d* pv = new Node_d;
	pv->d = d;
	pv->p = *pbeg;
	*pbeg = pv;
}

//Adding into end of deque
void addLast_d(Node_d** pend, double d) {
	Node_d* pv = new Node_d;
	pv->d = d;
	pv->p = 0;
	(*pend)->p = pv;
	*pend = pv;
}

//Output of first element
double delFirst_d(Node_d** pbeg) {
	double temp = (*pbeg)->d;
	Node_d* pv = *pbeg;
	*pbeg = (*pbeg)->p;
	delete pv;
	return temp;
}

//Output of last element
double delLast_d(Node_d** pend) {
	double temp = (*pend)->d;
	Node_d* pv = *pend;
	*pend = (*pend)->p;
	delete pv;
	return temp;
}
