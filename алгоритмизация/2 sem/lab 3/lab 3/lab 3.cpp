#include <iostream>
#include "3dVector.h"
using namespace std;

ostream& operator<<(ostream& out, Vector3d c) {
	out << c.getX() << " " << c.getY() << " " << c.getZ() << endl;
	return out;
}



int main() {
	Vector3d a (2, 6, 7);
	Vector3d b (1, 9, 2);
	Vector3d c = a + b;
	cout << c;
	c = a * b;
	cout << c;
}