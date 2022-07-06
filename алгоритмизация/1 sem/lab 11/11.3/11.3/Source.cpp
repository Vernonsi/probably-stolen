#include <iostream>
#include "Header.h"
using namespace std;

int main() {
	double N, M;
	cout << "NxM" << endl;
	cin >> N >> M;
	long double** NxM = new long double* [N];
	long double** NxM1 = new long double* [N];
	for (int i = 0; i < N; i++) {
		NxM[i] = new long double[M];
		NxM[i] = new long double[M];
	}
	initialize(NxM, N, M);
	display(NxM, N, M);
	cycle(NxM, NxM1, N, M);
	display(NxM, N, M);
	del(NxM);
}