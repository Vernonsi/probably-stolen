#include <iostream>
using namespace std;

template<class Type>
class mass {
	Type* a;
	int n;
public:
	mass(int N) {
		n = N;
		a = new Type[N];
	}

	mass(const mass<Type>& object) {
		n = object.n;
		a = object.a;
	}

	~mass() {
		delete[] a;
	}

	void ascend() {
		cout << "\nAscending\n";
		for (int i = 0; i < n; i++) {
			for (int m = 0; m < n; m++) {
				if (a[i] < a[m]) swap(a[i], a[m]);
			}
		}
	}

	void decend() {
		cout << "\nDecending\n";
		for (int i = 0; i < n; i++) {
			for (int m = 0; m < n; m++) {
				if (a[i] > a[m]) swap(a[i], a[m]);
			}
		}
	}



	friend ostream& operator<<(ostream& out, mass<Type>& b) {
		for (int i = 0; i < b.n; i++) {
			out << b.a[i] << " ";
		}
		return out;
	}


	friend istream& operator>>(istream& in, mass<Type>& b) {
		for (int i = 0; i < b.n; i++) {
			in >> b.a[i];
		}
		return in;
	}
};