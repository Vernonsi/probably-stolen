#include <iostream>
#include "SphereCyl.h"
using namespace std;

int main() {
	double x, y, z;
	cout << "center x\n";
	cin >> x;
	cout << "center y\n";
	cin >> y;
	cout << "center z\n";
	cin >> z;
	Point3d center = Point3d(x, y, z);
	double R;
	cout << "R\n";
	cin >> R;
	Sphere sphere = Sphere(center, R);
	cout << "Sphere info:\n";
	cout << "Center coordinates\n";
	cout << "X= " << sphere.getCenter().getX();
	cout << "\nY= " << sphere.getCenter().getY();
	cout << "\nZ= " << sphere.getCenter().getZ();
	cout << "\nRadius= " << sphere.getRadius();
	cout << "\nVolume= " << sphere.getVolume() << endl;

	double H;
	cout << "\nH\n";
	cin >> H;
	Cylinder cylinder = Cylinder(center, R,H);
	cout << "\nCylinder info:\n";
	cout << "Base center coordinates\n";
	cout << "X= " << cylinder.getCenter().getX();
	cout << "\nY= " << cylinder.getCenter().getY();
	cout << "\nZ= " << cylinder.getCenter().getZ();
	cout << "\nBase radius= " << cylinder.getRadius();
	cout << "\nH= " << cylinder.getH();
	cout << "\nVolume= " << cylinder.getVolume() << endl;
}