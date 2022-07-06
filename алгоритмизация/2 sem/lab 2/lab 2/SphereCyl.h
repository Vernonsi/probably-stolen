#include <iostream>
#include <math.h>
#define Pi       3.16159265358979323846
using namespace std;


class Point3d {
	double x, y, z;
public:
	Point3d(double X, double Y, double Z);
	double getX();
	double getY();
	double getZ();
};


class Sphere {
protected:
	double x, y, z;
	double R;
public:
	Sphere(Point3d center, double r);
	Sphere(double X, double Y, double Z, double r);
	Point3d getCenter();
	double getRadius();
	double getDiameter();
	double getVolume();
	void info();
};


class Cylinder :public Sphere {
	double H;
public:
	Cylinder(Point3d center, double r,double h);
	double getVolume();
	double getH();
	void info();
};