struct Node_d {
	double d;
	Node_d* p;
};

Node_d* first_d(double d);
double delFirst_d(Node_d** pbeg);
double delLast_d(Node_d** pend);
void addLast_d(Node_d** pend, double d);
void addFirst_d(Node_d** pbeg, double d);