struct Node_q {
	double d;
	Node_q* p;
};

Node_q* first_q(double d);
void add_q(Node_q** pbeg, double d);
double del_q(Node_q** pbeg);