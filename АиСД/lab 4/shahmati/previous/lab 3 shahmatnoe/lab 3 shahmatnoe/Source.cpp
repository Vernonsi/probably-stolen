//zero innovation zone
#include <iostream>
using namespace std;
int* ChooseDestinationPoint(int** board) {
	int N, M, F = -1;
check:
	cout << "vertical\n";
	cin >> M;
	cout << "gorizont\n";
	cin >> N;

	if (board[M - 1][N - 1] != 0 && board[M - 1][N - 1] != 9) {
		cout << "Another figure already claims this cell. Please choose different coordinates\n\n";
		goto check;
	}
	board[M - 1][N - 1] = F;
	int* F_info = new int[3];
	F_info[0] = M;
	F_info[1] = N;
	F_info[2] = F;
	return F_info;
}

void setBoard(int** board) {       // делаем пустую доску
	for (int m = 0; m < 8; m++) {
		for (int n = 0; n < 8; n++) {

			board[m][n] = 0;
		}
	}
}

const char* getPic(int n) {
	switch (n) {
	case 0: return " ";
	case 1: return "p"; case 10: return "P";
	case 2: return "r"; case 20: return "R";
	case 3: return "h"; case 30: return "H";
	case 4: return "b"; case 40: return "B";
	case 5: return "q";	case 50: return "Q";
	case 6: return "k"; case 60: return "K";
	case 9: return "x";
	case -1: return "O";
	default: return "problemi y menya aaaaaaaaaaaaaaaaaaa";
	}
}


void getBoard(int** board) {
	for (int m = 0; m < 8; m++) {					// рисуем доску
		for (int n = 0; n < 8; n++) {
			cout << "[" << getPic(board[m][n]) << "] ";
		}
		cout << endl;
	}
}

//future ahead
class YourFigure {
	int id;
public:
	YourFigure(int i) {
		id = i;
	}

	void moves(int** board, int* F, int counter) {
		switch (F[2]) {
		case 1: P_move(F[0], F[1], board, counter);
			break;
		case 2: R_move(F[0], F[1], board, counter);
			break;
		case 3: Kn_move(F[0], F[1], board, counter);
			break;
		case 4: B_move(F[0], F[1], board, counter);
			break;
		case 5: Q_move(F[0], F[1], board, counter);
			break;
		case 6: K_move(F[0], F[1], board, counter);
			break;
		default: break;
		}
	}
	void P_move(int n/*y*/, int m/*x*/, int** board, int status) { // в процессе
		int N = n - 1, M = m - 1;
		if (N - 1 < 8 && N - 1 >= 0) board[N-1][M]=status;
		if (N - 1 < 8 && N - 1 >= 0 && M - 1 < 8 && M - 1 >= 0 && (board[N - 1][M - 1] == 1/*2,3,4,5,6*/))  board[N - 1][M - 1] = status;
		if (N - 1 < 8 && N - 1 >= 0 && M + 1 < 8 && M + 1 >= 0 && board[N - 1][M + 1] == 0) board[N - 1][M + 1] = status;
	}

	int Kn_move(int n/*y*/, int m/*x*/, int** board, int status) { // supreme
		int N = n - 1, M = m - 1;
		if (N + 2 < 8 && N + 2 >= 0 && M + 1 < 8 && M + 1 >= 0 && (board[N + 2][M + 1] == 0 || board[N + 2][M + 1] > status || board[N + 2][M + 1] == -1)) {
			if (board[N + 2][M + 1] == -1) return status;
			else board[N + 2][M + 1] = status; //L
			//Kn_move(N + 2,M + 1, board, status + 1);
		}
		if (N + 2 < 8 && N + 2 >= 0 && M - 1 < 8 && M - 1 >= 0 && (board[N + 2][M - 1] == 0 || board[N + 2][M - 1] > status || board[N + 2][M - 1] == -1)) {
			if (board[N + 2][M - 1] == -1) return status;
			else board[N + 2][M - 1] = status; //L в другую сторону
			//Kn_move(N + 2, M - 1, board, status + 1);
		}
		if (N - 2 < 8 && N - 2 >= 0 && M - 1 < 8 && M - 1 >= 0 && (board[N - 2][M - 1] == 0 || board[N - 2][M - 1] > status || board[N - 2][M - 1] == -1)) {
			if (board[N - 2][M - 1] == -1) return status;
			else board[N - 2][M - 1] = status; // Г в другую сторону
			//Kn_move(N - 2, M - 1, board, status + 1);
		} 
		if (N - 2 < 8 && N - 2 >= 0 && M + 1 < 8 && M + 1 >= 0 && (board[N - 2][M + 1] == 0 || board[N - 2][M + 1] > status || board[N - 2][M + 1] == -1)) {
			if (board[N - 2][M + 1] == -1) return status;
			else board[N - 2][M + 1] = status; //Г
			//Kn_move(N - 2, M + 1, board, status + 1);
		}  
		if (N + 1 < 8 && N + 1 >= 0 && M + 2 < 8 && M + 2 >= 0 && (board[N + 1][M + 2] == 0 || board[N + 1][M + 2] > status || board[N + 1][M + 2] == -1)) {
			if (board[N + 1][M + 2] == -1) return status;
			else board[N + 1][M + 2] = status; //--| вниз
			//Kn_move(N + 1, M + 2, board, status + 1);
		}
		if (N - 1 < 8 && N - 1 >= 0 && M + 2 < 8 && M + 2 >= 0 && (board[N - 1][M + 2] == 0 || board[N - 1][M + 2] > status || board[N - 1][M + 2] == -1)) {
			if (board[N - 1][M + 2] == -1) return status;
			else board[N - 1][M + 2] = status;  //--| вверх
			//Kn_move(N - 1, M + 2, board, status + 1);
		}
		if (N - 1 < 8 && N - 1 >= 0 && M - 2 < 8 && M - 2 >= 0 && (board[N - 1][M - 2] == 0 || board[N - 1][M - 2] > status || board[N - 1][M - 2] == -1)) {
			if (board[N - 1][M - 2] == -1) return status;
			else board[N - 1][M - 2] = status;   // |-- вверх
			/*Kn_move(N - 1, M - 2, board, status + 1);*/
		}
		if (N + 1 < 8 && N + 1 >= 0 && M - 2 < 8 && M - 2 >= 0 && (board[N + 1][M - 2] == 0 || board[N + 1][M - 2] > status || board[N + 1][M - 2] == -1)) {
			if (board[N + 1][M - 2] == -1) return status;
			else board[N + 1][M - 2] = status;   // |-- вниз
		/*	Kn_move(N + 1, M - 2, board, status + 1);*/
		} 
		return 0;
	}

	void R_move(int n/*y*/, int m/*x*/, int** board, int status) { // в процессе
		int N = n - 1, M = m - 1;
		while (N + 1 < 8 && N + 1 >= 0 && M < 8 && M >= 0 && (board[N + 1][M] == 0 || board[N + 1][M] == 9)) {
			board[N + 1][M] = status; //vniz
			N++;
		}
		N = n - 1, M = m - 1;
		while (N - 1 < 8 && N - 1 >= 0 && M < 8 && M >= 0 && (board[N - 1][M] == 0 || board[N - 1][M] == 9)) {
			board[N - 1][M] = status; //vverh
			N--;
		}
		N = n - 1, M = m - 1;
		while (N < 8 && N >= 0 && M + 1 < 8 && M + 1 >= 0 && (board[N][M + 1] == 0 || board[N][M + 1] == 9)) {
			board[N][M + 1] = status; // napravo
			M++;
		}
		N = n - 1, M = m - 1;
		while (N < 8 && N >= 0 && M - 1 < 8 && M - 1 >= 0 && (board[N][M - 1] == 0 || board[N][M - 1] == 9)) {
			board[N][M - 1] = status; // nalevo
			M--;
		}
	}

	void B_move(int n/*y*/, int m/*x*/, int** board, int status) {
		int N = n - 1, M = m - 1;
		while (N + 1 < 8 && N + 1 >= 0 && M + 1 < 8 && M + 1 >= 0 && (board[N + 1][M + 1] == 0 || board[N + 1][M + 1] == 9)) {
			board[N + 1][M + 1] = status; // naprovo-vniz
			N++;
			M++;
		}
		N = n - 1, M = m - 1;
		while (N + 1 < 8 && N + 1 >= 0 && M - 1 < 8 && M - 1 >= 0 && (board[N + 1][M - 1] == 0 || board[N + 1][M - 1] == 9)) {
			board[N + 1][M - 1] = status; // nalevo-vniz
			N++;
			M--;
		}
		N = n - 1, M = m - 1;
		while (N - 1 < 8 && N - 1 >= 0 && M + 1 < 8 && M + 1 >= 0 && (board[N - 1][M + 1] == 0 || board[N - 1][M + 1] == 9)) {
			board[N - 1][M + 1] = status; // naprovo-vverh
			N--;
			M++;
		}
		N = n - 1, M = m - 1;
		while (N - 1 < 8 && N - 1 >= 0 && M - 1 < 8 && M - 1 >= 0 && (board[N - 1][M - 1] == 0 || board[N - 1][M - 1] == 9)) {
			board[N - 1][M - 1] = status; // nalevo-vverh
			N--;
			M--;
		}

	}

	void Q_move(int n/*y*/, int m/*x*/, int** board, int status) {
		R_move(n, m, board, 9);
		B_move(n, m, board, 9);
	}


	void K_move(int n/*y*/, int m/*x*/, int** board, int status) {
		int N = n - 1, M = m - 1;
		if (N - 1 < 8 && N - 1 >= 0 && M - 1 < 8 && M - 1 >= 0 && board[N - 1][M - 1] == 0) board[N - 1][M - 1] = status;
		if (N - 1 < 8 && N - 1 >= 0 && M < 8 && M >= 0 && board[N - 1][M] == 0) board[N - 1][M] = status;
		if (N - 1 < 8 && N - 1 >= 0 && M + 1 < 8 && M + 1 >= 0 && board[N - 1][M + 1] == 0) board[N - 1][M + 1] = status;
		if (N < 8 && N >= 0 && M - 1 < 8 && M - 1 >= 0 && board[N][M - 1] == 0) board[N][M - 1] = status;
		if (N < 8 && N >= 0 && M + 1 < 8 && M + 1 >= 0 && board[N][M + 1] == 0) board[N][M + 1] = status;
		if (N + 1 < 8 && N + 1 >= 0 && M + 1 < 8 && M + 1 >= 0 && board[N + 1][M - 1] == 0) board[N + 1][M - 1] = status;
		if (N + 1 < 8 && N + 1 >= 0 && M < 8 && M >= 0 && board[N + 1][M] == 0) board[N + 1][M] = status;
		if (N + 1 < 8 && N + 1 >= 0 && M + 1 < 8 && M + 1 >= 0 && board[N + 1][M + 1] == 0) board[N + 1][M + 1] = status;
	}

};



int main(){
	int** path_board = new int* [8];
	for (int i = 0; i < 8; i++) {
		path_board[i] = new int[8];
	}
	setBoard(path_board);

	int* destination = new int[3];
	cout << "Choose destination point\n";
	destination = ChooseDestinationPoint(path_board);

	cout << endl;

	cout << "\n\npath\n\n";
	getBoard(path_board);
	YourFigure a(1);
	int counter = 1;
	int y, x;
	cin >> y >> x;
	counter=a.Kn_move(y, x, path_board, counter);

	int k = 0;
	int destiny	 = a.Kn_move(y, x, path_board, counter);
	if (destiny == counter) goto end;
	for (int m = 0; m < 8; m++) {
		for (int n = 0; n < 8; n++,counter++) {
			if (path_board[m][n] != 0 && path_board[m][n] <= counter && path_board[m][n] != -1) {

				k=a.Kn_move(m,n, path_board, counter);
			}
			
		}
	}
	
end:
	for (int m = 0; m < 8; m++) {					// рисуем доску
		for (int n = 0; n < 8; n++) {
			cout << "[" <<(path_board[m][n]) << "] ";
		}
		cout << endl;
	}

	cout << endl << counter << " "<< k;
}