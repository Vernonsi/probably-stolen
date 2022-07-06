#include <iostream>
using namespace std;
void initialize(long double** NxM , double N, double M) {
	for (int a = 0; a < N; a++) {
		for (int i = 0; i < M; i++) {
			cin >> NxM[a][i];
		}
		
	}
	cout << endl;
}
void display(long double** NxM, double N, double M){
	for (int a = 0; a < N; a++) {
		for (int i = 0; i < M; i++) {
			cout << NxM[a][i] << " ";
		}
		cout << endl;
	}
}
void loc_min(long double** NxM, double N, double M) {

	

	int loc = 0;
int  q=0;
	for (int a = 0; a < N; a++) {
		for (int i = 0; i < M; i++) {
			/*1*/if (i > 0) {
				if (NxM[a][i] < NxM[a][i - 1]) q = 1;
				else q=-1;
			} 
			/*2*/	if (q != -1) {
				if (i < M - 1) {
					if (NxM[a][i] < NxM[a][i + 1]) q = 1;
					else q = -1;
				}
			} 
			/*3*/if (q != -1) {
				if (a > 0) {
				if (NxM[a][i] < NxM[a - 1][i]) q = 1;
				else q = -1;
			}
			}
			/*4*/if (q != -1) {
				if (a < N - 1) {
					if (NxM[a][i] < NxM[a + 1][i]) q = 1;
					else q = -1;
				}
						}
			/*5*/if (q != -1) {
				if (a > 0 && i > 0) {
					if (NxM[a][i] < NxM[a - 1][i - 1]) q = 1;
					else q = -1;
				}
			}
			/*6*/if (q != -1) {
				if (a > 0 && i < M - 1) {
					if (NxM[a][i] < NxM[a - 1][i + 1]) q = 1;
					else q = -1;
				}
			}
			/*7*/if (q != -1) {
				if (a < N - 1 && i>0) {
					if (NxM[a][i] < NxM[a + 1][i - 1]) q = 1;
					else q = -1;
				}
			}
			/*8*/if (q != -1) {
				if (a < N - 1 && i < M - 1) {
					if (NxM[a][i] < NxM[a + 1][i + 1]) q = 1;
					else q = -1;
				}
			}


				if (q==1) loc ++;
				q = 0;
		}
	}
	 cout << endl << loc << " eto vot loc MIN";
		
	}
void del(long double** masiv) {
	delete[]masiv;
}

int main() {
    double N, M;
	cout << "NxM" << endl;
	cin >> N >> M;
	long double** NxM = new long double* [N];
	for (int i = 0; i < N; i++) {
		NxM[i] = new long double[M];
	}
		initialize(NxM,N,M);
		display(NxM, N, M);
		loc_min(NxM, N, M); 
		del(NxM);

}