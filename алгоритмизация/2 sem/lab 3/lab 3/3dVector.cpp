#include <iostream>
#include "3dVector.h"


Vector3d:: Vector3d(double X, double Y, double Z) {
	x = X;
	y = Y;
	z = Z;
}
double Vector3d::getX() {
	return x;
}
double  Vector3d::getY() {
	return y;
}
double Vector3d::getZ() {
	return z;
}
Vector3d Vector3d:: operator+(Vector3d right) {
	Vector3d sum = Vector3d(getX() + right.getX(), getY() + right.getY(), getZ() + right.getZ());
	return sum;
}
Vector3d Vector3d:: operator*(Vector3d right) {
	Vector3d pr = Vector3d(getY()*right.getZ()-getZ()*right.getY(),getZ()*right.getX()-getX()*right.getZ(),getX()*right.getY()-getY()*right.getX());
	return pr;
}
//ostream& operator<<(ostream& out, Vector3d c) {
//	out << c.getX() << " " << c.getY() << " " << c.getZ() << endl;
//	return out;
//}