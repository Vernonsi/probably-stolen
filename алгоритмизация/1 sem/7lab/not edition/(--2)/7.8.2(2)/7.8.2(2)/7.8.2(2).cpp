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
void cycle(long double** NxM, double N, double M) {
	int step;
	cout << endl << "shag ";
	cin >> step;
	int b = N-1;
	double* g = new double [M];
	for (int i = 0; i < M; i++) {
		g[i] = NxM[b][i];
	}
	cout << endl;
	int i = 0;
	for (int d=0;d<step;d++){
		for (int a = 0; a < N; a++) {
			for (int i = 0; i < M; i++) {
				if (a < N - 1) {
					g[i] = NxM[a][i];
					NxM[a][i] = NxM[a + 1][i];
					NxM[a + 1][i] = g[i];
				}
			}
		}
	}

	/////////*for (int a = 0; a < N; a++) {
	////////	for (int i = 0; i < M; i++) {
	////////		g[i] = NxM[b][i];
	////////	}
	////////	if (a > 0) {
	////////		NxM[a][i] = NxM[a - 1][i];
	////////		NxM[a - 1][i] = g[i];
	////////	}
	////////}*/
	/*for (int d = 0; d < step; d++) {
		for (int a = N; a > N; a--) {
			for (int i = 0; i < M; i++) {
				g[i] = NxM[b][i];
				NxM[a][i] = NxM[a - 1][i];
				if (a == 0) { 
					NxM[a][i] = g[i];

				}
			}
		}
	}*/
}
int main() {
	double N, M;
	cout << "NxM" << endl;
	cin >> N >> M;
	long double** NxM = new long double* [N];
	for (int i = 0; i < N; i++) {
		NxM[i] = new long double[M];
	}
	initialize(NxM, N, M);
	display(NxM, N, M);
	cycle(NxM, N, M);
	display(NxM, N, M);
}