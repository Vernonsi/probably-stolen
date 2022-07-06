#include <iostream>
#include "Header.h"
using namespace std;

void initialize(long double** NxM, double N, double M) {
	for (int a = 0; a < N; a++) {
		for (int i = 0; i < M; i++) {
			NxM[a][i] = 10 + rand() % 90;
		}

	}
	cout << endl;
}

void display(long double** NxM, double N, double M) {
	for (int a = 0; a < N; a++) {
		for (int i = 0; i < M; i++) {
			cout << NxM[a][i] << " ";
		}
		cout << endl;
	}
}
void cycle(long double** NxM, long double** NxM1, double N, double M) {
	int step;
	cout << endl << "shag ";
	cin >> step;
	int b = N - 1;
	double* g = new double[M];
	double* a0 = new double[M];
	double* a1 = new double[M];
	for (int i = 0; i < M; i++) {
		g[i] = NxM[b][i];
	}
	cout << endl;
	int n = N - 1;
	for (int d = 0; d < step; d++) {
		for (int i = 0; i < M; i++) {
			a0[i] = NxM[0][i];
			a1[i] = NxM[n][i];
		}
		for (int a = N - 1; a > 0; a--) {

			for (int i = 0; i < M; i++) {

				if (a < N) {
					NxM[a][i] = NxM[a - 1][i];
				}
				if (a == 1) {
					NxM[0][i] = a1[i];
				}
			}
		}
	}
}
void del(long double** NxM) {
	delete[]NxM;
}