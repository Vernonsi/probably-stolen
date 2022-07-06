#include <iostream>
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
void cycle(long double** NxM, long double** nXm, double N, double M) {
	int step;
	cout << endl << "shag ";
	cin >> step;
	int b = N - 1;
	double* g = new double[M];
	for (int i = 0; i < M; i++) {
		g[i] = NxM[b][i];
	}
	cout << endl;
	int i = 0;
	/*for (int d=0;d<step;d++){ 
		for (int a = 0; a < N; a++) {
			for (int i = 0; i < M; i++) {
				if (a - 1>= 0)	nXm[a][i] = NxM[a -1][i];
				else nXm[a][i] = NxM[a - 1][i];
			}
		}
 } */

	for (int a = 0; a < N; a++) {
		for (int i = 0; i < M; i++) {
			//if (a - 1 >= 0)	nXm[a][i] = NxM[a - 1][i];
			//else nXm[a][i] = NxM[a - 1][i];
			nXm[a][i] = NxM[abs(a - step)][i];
			if(abs(a-step)==a){}
		}
	}

}
int main() {
	double N, M;
	cout << "NxM" << endl;
	cin >> N >> M;
	long double** NxM = new long double* [N];
	long double** nXm = new long double* [N];
	for (int i = 0; i < N; i++) {
		NxM[i] = new long double[M];
		nXm[i] = new long double[M];
	}
	initialize(NxM, N, M);
	display(NxM, N, M);
	cycle(NxM,nXm, N, M);
	display(nXm, N, M);
}