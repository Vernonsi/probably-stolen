class Vector3d {
	double x, y, z;
public:
	Vector3d(double X, double Y, double Z);
	double getX();
	double getY();
	double getZ();
	Vector3d operator+(Vector3d right);
	Vector3d operator*(Vector3d right);
};
//ostream& operator<<(ostream& out, Vector3d a);
