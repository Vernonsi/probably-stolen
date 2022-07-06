#include <iostream>
using namespace std;
//void initialize(long double** NxM, double N, double M) {
//	for (int a = 0; a < N; a++) {
//		for (int i = 0; i < M; i++) {
//			cin >> NxM[a][i];
//		}
//
//	}
//	cout << endl;
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
	int n= N-1;
	for (int d = 0; d < step; d++) {
		for (int i = 0; i < M; i++) {
				a0[i] = NxM[0][i];
				a1[i] = NxM[n][i];
			}
		for (int a = N-1; a>0; a--) {
			
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
	cycle(NxM, NxM1,N, M);
	display(NxM, N, M);
	del(NxM);
}