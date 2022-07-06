#include <iostream>
#include "SphereCyl.h"

Point3d::Point3d(double X, double Y, double Z) {
	x = X;
	y = Y;
	z = Z;
}
double Point3d::getX() {
	return x;
}
double Point3d::getY() {
	return y;
}
double Point3d::getZ() {
	return z;
}

Sphere::Sphere(Point3d center, double r) {
	x = center.getX();
	y = center.getY();
	z = center.getZ();
	R = r;
}
Sphere::Sphere(double X, double Y, double Z, double r) {
	x = X;
	y = Y;
	z = Z;
	R = r;
}
Point3d Sphere::getCenter() {
	Point3d center = Point3d(x, y, z);
	return center;
}
double Sphere::getRadius() {
	return R;
}
double Sphere::getDiameter() {
	return 2 * R;
}
double Sphere::getVolume() {
	double V = 4 / 3 * Pi * pow(R, 3);
	return V;
}
void Sphere::info() {
	cout << "Sphere info:\n";
	cout << "Center coordinates\n";
	cout << "X= " << x;
	cout << "\nY= " << y;
	cout << "\nZ= " << z;
	cout << "\n Radius= " << R;
	cout << "\n Volume= " << getVolume();
}

Cylinder::Cylinder(Point3d center, double r, double h) : Sphere(center, r) {
	x = center.getX();
	y = center.getY();
	z = center.getZ();
	R = r;
	H = h;
}
double Cylinder::getVolume() {
	double V = Pi * R * R * H;
	return V;
}
double Cylinder::getH() {
	return H;
}
void Cylinder::info() {
	cout << "Cylinder info:\n";
	cout << "Center coordinates\n";
	cout << "X= " << x;
	cout << "\nY= " << y;
	cout << "\nZ= " << z;
	cout << "\n Base radius= " << R;
	cout << "\n Volume= " << getVolume();
	cout << "\n H= " << getH();
}