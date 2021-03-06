#include <iostream>
using namespace std;


//class Identify {
//	int id;
//	const char* pic;
//public:
//	const char* getPic(int n) {
//		switch (n) {
//		case 0: return " ";
//		case 1: return "p";
//		case 2: return "r";
//		case 3: return "kn";
//		case 4: return "b";
//		case 5: return "q";
//		case 6: return "k";
//		case 9: return "x";
//		default: return "problemi y menya aaaaaaaaaaaaaaaaaaa";
//		}
//	}
//};
//class Empty {
//	const int id = 0;
//	const char* pic = " ";
//};
//class Pawn {
//	const int id = 1;
//	const char* pic = "p";
//	void attack(int N/*y*/, int M/*x*/, int** board, int status) { // в процессе
//		if (board[N - 1][M - 1] && board[N - 1][M - 1] == 0) board[N - 1][M - 1] = status;
//		if (board[N - 1][M + 1] && board[N - 1][M + 1] == 0) board[N - 1][M + 1] = status;
//	}
//};
//class Rook {
//	const int id = 2;
//	const char* pic = "r";
//};
//class Knight {
//		const int id = 3;
//		const char* pic = "kn";
//		void attack(int N/*y*/, int M/*x*/, int** board, int status) { // в процессе
//			if (board[N + 2][M + 1] && board[N + 2][M + 1] == 0) board[N + 2][M + 1] = status; //L
//			if (board[N + 2][M - 1] && board[N + 2][M - 1] == 0) board[N + 2][M - 1] = status; //L в другую сторону
//			if (board[N - 2][M - 1] && board[N - 2][M - 1] == 0) board[N - 2][M - 1] = status; // Г в другую сторону
//			if (board[N - 2][M + 1] && board[N - 2][M + 1] == 0) board[N - 2][M + 1] = status; //Г
//			if (board[N + 1][M + 2] && board[N + 1][M + 2] == 0) board[N + 1][M + 2] = status; //--| вниз
//			if (board[N - 1][M + 2] && board[N - 1][M + 2] == 0) board[N - 1][M + 2] = status; //--| вверх
//			if (board[N - 1][M - 2] && board[N - 1][M - 2] == 0) board[N - 1][M - 2] = status; // |-- вверх
//			if (board[N + 1][M - 2] && board[N + 1][M - 2] == 0) board[N + 1][M - 2] = status; // |-- вниз
//		}
//};
//class Bishop {
//	const int id = 4;
//	const char* pic = "b";
//};
//class Queen {
//	const int id = 5;
//	const char* pic = "q";
//};
//class King {
//	const int id = 6;
//	const char* pic = "k";
//};


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
	case 99: return "O";
	default: return /*"problemi y menya aaaaaaaaaaaaaaaaaaa"*/ "n";
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

void P_attack(int n/*y*/, int m/*x*/, int** board, int status) { // в процессе
	int N = n - 1, M = m - 1;
	if (N + 1 < 8 && N + 1 >= 0 && M - 1 < 8 && M - 1 >= 0 && board[N + 1][M - 1] == 0) board[N + 1][M - 1] = status;
	if (N + 1 < 8 && N + 1 >= 0 && M + 1 < 8 && M + 1 >= 0 && board[N + 1][M + 1] == 0) board[N + 1][M + 1] = status;
}

void Kn_attack(int n/*y*/, int m/*x*/, int** board, int status) { // в процессе
	int N = n - 1, M = m - 1;
	if (N + 2 < 8 && N + 2 >= 0 && M + 1 < 8 && M + 1 >= 0 && board[N + 2][M + 1] == 0) board[N + 2][M + 1] = status; //L
	if (N + 2 < 8 && N + 2 >= 0 && M - 1 < 8 && M - 1 >= 0 && board[N + 2][M - 1] == 0) board[N + 2][M - 1] = status; //L в другую сторону
	if (N - 2 < 8 && N - 2 >= 0 && M - 1 < 8 && M - 1 >= 0 && board[N - 2][M - 1] == 0) board[N - 2][M - 1] = status; // Г в другую сторону
	if (N - 2 < 8 && N - 2 >= 0 && M + 1 < 8 && M + 1 >= 0 && board[N - 2][M + 1] == 0) board[N - 2][M + 1] = status; //Г
	if (N + 1 < 8 && N + 1 >= 0 && M + 2 < 8 && M + 2 >= 0 && board[N + 1][M + 2] == 0) board[N + 1][M + 2] = status; //--| вниз
	if (N - 1 < 8 && N - 1 >= 0 && M + 2 < 8 && M + 2 >= 0 && board[N - 1][M + 2] == 0) board[N - 1][M + 2] = status; //--| вверх
	if (N - 1 < 8 && N - 1 >= 0 && M - 2 < 8 && M - 2 >= 0 && board[N - 1][M - 2] == 0) board[N - 1][M - 2] = status; // |-- вверх
	if (N + 1 < 8 && N + 1 >= 0 && M - 2 < 8 && M - 2 >= 0 && board[N + 1][M - 2] == 0) board[N + 1][M - 2] = status; // |-- вниз
}

void R_attack(int n/*y*/, int m/*x*/, int** board, int status) { // в процессе
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

void B_attack(int n/*y*/, int m/*x*/, int** board, int status) {
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

void Q_attack(int n/*y*/, int m/*x*/, int** board, int status) {
	R_attack(n, m, board, 9);
	B_attack(n, m, board, 9);
}


void K_attack(int n/*y*/, int m/*x*/, int** board, int status) {
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

int* ChooseFigure(int** board) {
	int N, M, F;
check:
	cout << "vertical\n";
	cin >> M;
	cout << "gorizont\n";
	cin >> N;
	cout << "choose figure\n" << "1 pawn; 2 rook; 3 knight(horse); 4 bishop; 5 queen; 6 king\n";
	cin >> F;
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
int* ChooseAllyFigure(int** board) {
	int N, M, F;
check:
	cout << "vertical\n";
	cin >> M;
	cout << "gorizont\n";
	cin >> N;
	cout << "choose figure\n" << "1 pawn; 2 rook; 3 knight(horse); 4 bishop; 5 queen; 6 king\n";
	cin >> F;
	if (board[M - 1][N - 1] != 0 && board[M - 1][N - 1] != 9) {
		cout << "Another figure already claims this cell. Please choose different coordinates\n\n";
		goto check;
	}
	board[M - 1][N - 1] = F * 10;
	int* F_info = new int[3];
	F_info[0] = M;
	F_info[1] = N;
	F_info[2] = F;
	return F_info;
}

int* ChooseDestinationPoint(int** board) {
	int N, M, F = 99;
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

void attacks(int** board, int* F) {
	switch (F[2]) {
	case 1: P_attack(F[0], F[1], board, 9);
		break;
	case 2: R_attack(F[0], F[1], board, 9);
		break;
	case 3: Kn_attack(F[0], F[1], board, 9);
		break;
	case 4: B_attack(F[0], F[1], board, 9);
		break;
	case 5: Q_attack(F[0], F[1], board, 9);
		break;
	case 6: K_attack(F[0], F[1], board, 9);
		break;
	default: break;
	}
}

void setBoard(int** board) {       // делаем пустую доску
	for (int m = 0; m < 8; m++) {
		for (int n = 0; n < 8; n++) {

			board[m][n] = 0;
		}
	}
}

bool Kn_move(int n/*y*/, int m/*x*/, int** board, int status) { // в процессе
	bool fate = 0;
	int N = n, M = m;
	if (N + 2 < 8 && N + 2 >= 0 && M + 1 < 8 && M + 1 >= 0 && (board[N + 2][M + 1] == 0 || board[N + 2][M + 1] == 99)) {
		if (board[N + 2][M + 1] == 99) fate = 1;

		board[N + 2][M + 1] = status; //L
	}
	if (N + 2 < 8 && N + 2 >= 0 && M - 1 < 8 && M - 1 >= 0 && (board[N + 2][M - 1] == 0 || board[N + 2][M - 1] == 99)) {
		if (board[N + 2][M - 1] == 99) fate = 1;
		board[N + 2][M - 1] = status; //L в другую сторону
	}
	if (N - 2 < 8 && N - 2 >= 0 && M - 1 < 8 && M - 1 >= 0 && (board[N - 2][M - 1] == 0 || board[N - 2][M - 1] == 99)) {
		if (board[N - 2][M - 1] == 99) fate = 1;
		board[N - 2][M - 1] = status; // Г в другую сторону
	}
	if (N - 2 < 8 && N - 2 >= 0 && M + 1 < 8 && M + 1 >= 0 && (board[N - 2][M + 1] == 0 || board[N - 2][M + 1] == 99)) {
		if (board[N - 2][M + 1] == 99) fate = 1;
		board[N - 2][M + 1] = status; //Г
	}
	if (N + 1 < 8 && N + 1 >= 0 && M + 2 < 8 && M + 2 >= 0 && (board[N + 1][M + 2] == 0 || board[N + 1][M + 2] == 99)) {
		if (board[N + 1][M + 2] == 99) fate = 1;
		board[N + 1][M + 2] = status; //--| вниз
	}
	if (N - 1 < 8 && N - 1 >= 0 && M + 2 < 8 && M + 2 >= 0 && (board[N - 1][M + 2] == 0 || board[N - 1][M + 2] == 99)) {
		if (board[N - 1][M + 2] == 99) fate = 1;
		board[N - 1][M + 2] = status; //--| вверх
	}
	if (N - 1 < 8 && N - 1 >= 0 && M - 2 < 8 && M - 2 >= 0 && (board[N - 1][M - 2] == 0 || board[N - 1][M - 2] == 99)) {
		if (board[N - 1][M - 2] == 99) fate = 1;
		board[N - 1][M - 2] = status; // |-- вверх
	}
	if (N + 1 < 8 && N + 1 >= 0 && M - 2 < 8 && M - 2 >= 0 && (board[N + 1][M - 2] == 0 || board[N + 1][M - 2] == 99)) {
		if (board[N + 1][M - 2] == 99) fate = 1;
		board[N + 1][M - 2] = status; // |-- вниз
	}
	return fate;
}

int blind_search(int** board, int counter) {
	bool checking = 0;
	int i = counter;
	for (int t = 0; t < 99; t++) {
		for (int m = 0; m < 8; m++) {
			for (int n = 0; n < 8; n++) {
				if (board[n][m] == i) {
					checking = Kn_move(n, m, board, i - 1);
				}
				if (checking) {
					return i;// или лучше fabs(i)?
					goto end;
				}
			}
		}
		i--;
	}
end:
	return 0;
}

int** search_and_destroy(int** no_attack_board/*no_attack_board*/, int* F_info/**/, int** attack/*attacks*/, int eF, int counter) {
	int** board = no_attack_board;
	for (int i = 0; i < eF; i++) {
		if (attack[i][0] == F_info[0] && attack[i][1] == F_info[1])  attack[i][3] = 0;
	}
	for (int i = 0; i < eF; i++) {
		attacks(board, attack[i]);
	}
	// в теории мы убираем фигуру, котрую мы бьем с поля
	// надо бы еще чекнуть если там окажутся 9ки
	if (board[F_info[0]][F_info[1]] == 0) {
		board[F_info[0]][F_info[1]] = counter;
		blind_search(board, counter);
	}
	// Kn_move(F_info[0], F_info[1], board, counter);
	// может еще одну функцию где у тебя там в мейне, только функция ебана в рот когда это все закончится
	return board;

}

void equal(int** board1, int** board2, int size) {  // *1* =*2*
	for (int m = 0; m < size; m++) {
		for (int n = 0; n < size; n++) {
			board1[m][n] = board2[m][n];
		}
	}
}

int** mergeBoards(int** board1, int** board2) {
	int** fin_board = new int* [8];
	for (int i = 0; i < 8; i++) {
		fin_board[i] = new int[8];
	}
	//for (int m = 0; m < 8; m++) {
	//	for (int n = 0; n < 8; n++) {
	//		fin_board[m][n] = board1[m][n];
	//	}
	//} 
	equal(fin_board, board1,8);

	for (int m = 0; m < 8; m++) {
		for (int n = 0; n < 8; n++) {
			if (board1[m][n] != board2[m][n]) {
				if (board1[m][n] == 9 && board2[m][n] != 9) fin_board[m][n] = board2[m][n];
				if (board2[m][n] == 9 && board1[m][n] != 9) fin_board[m][n] = board1[m][n];
				if (board1[m][n]<0 && board1[m][n]>board2[m][n]) fin_board[m][n] = board1[m][n];
				if (board2[m][n]<0 && board2[m][n]>board1[m][n]) fin_board[m][n] = board2[m][n];
				if ((board1[m][n]>0 && board1[m][n] <7) && board2<0 ) fin_board[m][n] = board2[m][n];
				if ((board2[m][n] > 0 && board2[m][n] < 7) && board1 < 0) fin_board[m][n] = board1[m][n];
				if (board1[m][n] != 99 && board2[m][n] == 99) fin_board[m][n] = board2[m][n];
				if (board2[m][n] != 99 && board1[m][n] == 99) fin_board[m][n] = board1[m][n];
			}
		}
	}
	return fin_board;

}



int Kn_rec_move(int n/*y*/, int m/*x*/, int** figure_board, int** path_board, int status, int** Attack, int eF) { // в процессе
	if (status <-10) return -99;
	

	int** board = new int* [8];
	for (int i = 0; i < 8; i++) {
		board[i] = new int[8];
	}
	equal(board, path_board,8);
	int** f_board = new int* [8];
	for (int i = 0; i < 8; i++) {
		f_board[i] = new int[8];
	}
	equal(f_board, figure_board,8);
	int** attack = new int* [eF];
	for (int i = 0; i < eF; i++) {
		attack[i] = new int[3];
	}
	equal(attack, Attack, eF);
	int N = n, M = m;
	
	int move1 = -99;
	if (N + 2 < 8 && N + 2 >= 0 && M + 1 < 8 && M + 1 >= 0 && (board[N + 2][M + 1] == 0 || board[N + 2][M + 1] == 99 ||(board[N + 2][M + 1] >0 && board[N + 2][M + 1] <7))) {
		if (board[N + 2][M + 1] == 99) return status;
		if (board[N + 2][M + 1] > 0 && board[N + 2][M + 1] < 7) {
			for (int i = 0; i < eF; i++) {
				if (attack[i][0] == N + 2 && attack[i][1] == M + 1)  attack[i][2] = 0;
			}
			for (int i = 0; i < eF; i++) {
				attacks(f_board, attack[i]);
				board = mergeBoards(board, f_board); // в теории на этом шаге мы убрали фигуру и ее последствия
			}
		}

		board[N + 2][M + 1] = status; //L
		move1 = Kn_rec_move(N + 2, M + 1, f_board, board, status - 1, attack, eF);
		
	}
	equal(board, path_board, 8);
	equal(f_board, figure_board, 8);
	equal(attack, Attack, eF);
	int move2 = -99;
	if (N + 2 < 8 && N + 2 >= 0 && M - 1 < 8 && M - 1 >= 0 && (board[N + 2][M - 1] == 0 || board[N + 2][M - 1] == 99 || (board[N + 2][M - 1] > 0 && board[N + 2][M - 1] < 7))) {
		if (board[N + 2][M - 1] == 99) return status;
		if (board[N + 2][M - 1] > 0 && board[N + 2][M - 1] < 7) {
			for (int i = 0; i < eF; i++) {
				if (attack[i][0] == N + 2 && attack[i][1] == M - 1)  attack[i][2] = 0;
			}
			for (int i = 0; i < eF; i++) {
				attacks(f_board, attack[i]);
				board = mergeBoards(board, f_board); // в теории на этом шаге мы убрали фигуру и ее последствия
			}
		}

		board[N + 2][M - 1] = status; //L в другую сторону
		move2 = Kn_rec_move(N + 2, M - 1, f_board, board, status - 1, attack, eF);

	}
	equal(board, path_board, 8);
	equal(f_board, figure_board, 8);
	equal(attack, Attack, eF);
	int move3 = -99;
	if (N - 2 < 8 && N - 2 >= 0 && M - 1 < 8 && M - 1 >= 0 && (board[N - 2][M - 1] == 0 || board[N - 2][M - 1] == 99 || (board[N - 2][M - 1] > 0 && board[N - 2][M - 1] < 7))) {
		if (board[N - 2][M - 1] == 99) return status;
		if (board[N - 2][M - 1] > 0 && board[N - 2][M - 1] < 7) {
			for (int i = 0; i < eF; i++) {
				if (attack[i][0] == N - 2 && attack[i][1] == M - 1)  attack[i][2] = 0;
			}
			for (int i = 0; i < eF; i++) {
				attacks(f_board, attack[i]);
				board = mergeBoards(board, f_board); // в теории на этом шаге мы убрали фигуру и ее последствия
			}
		}

		board[N - 2][M - 1] = status; // Г в другую сторону
		move3 = Kn_rec_move(N - 2, M - 1, f_board, board, status - 1, attack, eF);

	}
	equal(board, path_board, 8);
	equal(f_board, figure_board, 8);
	equal(attack, Attack, eF);
	int move4 = -99;
	if (N - 2 < 8 && N - 2 >= 0 && M + 1 < 8 && M + 1 >= 0 && (board[N - 2][M + 1] == 0 || board[N - 2][M + 1] == 99 || (board[N - 2][M + 1] > 0 && board[N - 2][M + 1] < 7))) {
		if (board[N - 2][M + 1] == 99) return status;
		if (board[N - 2][M + 1] > 0 && board[N - 2][M + 1] < 7) {
			for (int i = 0; i < eF; i++) {
				if (attack[i][0] == N - 2 && attack[i][1] == M + 1)  attack[i][2] = 0;
			}
			for (int i = 0; i < eF; i++) {
				attacks(f_board, attack[i]);
				board = mergeBoards(board, f_board); // в теории на этом шаге мы убрали фигуру и ее последствия
			}
		}

		board[N - 2][M + 1] = status; //Г
		move4 = Kn_rec_move(N - 2, M + 1, f_board, board, status - 1, attack, eF);

	}
	equal(board, path_board, 8);
	equal(f_board, figure_board, 8);
	equal(attack, Attack, eF);
	int move5 = -99;
	if (N + 1 < 8 && N + 1 >= 0 && M + 2 < 8 && M + 2 >= 0 && (board[N + 1][M + 2] == 0 || board[N + 1][M + 2] == 99 || (board[N + 1][M + 2] > 0 && board[N + 1][M + 2] < 7))) {
		if (board[N + 1][M + 2] == 99) return status;
		if (board[N + 1][M + 2] > 0 && board[N + 1][M + 2] < 7) {
			for (int i = 0; i < eF; i++) {
				if (attack[i][0] == N + 1 && attack[i][1] == M + 2)  attack[i][2] = 0;
			}
			for (int i = 0; i < eF; i++) {
				attacks(f_board, attack[i]);
				board = mergeBoards(board, f_board); // в теории на этом шаге мы убрали фигуру и ее последствия
			}
		}

		board[N + 1][M + 2] = status; //--| вниз
		move5 = Kn_rec_move(N + 1, M + 2, f_board, board, status - 1, attack, eF);

	}
	equal(board, path_board, 8);
	equal(f_board, figure_board, 8);
	equal(attack, Attack, eF);
	int move6 = -99;
	if (N - 1 < 8 && N - 1 >= 0 && M + 2 < 8 && M + 2 >= 0 && (board[N - 1][M + 2] == 0 || board[N - 1][M + 2] == 99 || (board[N - 1][M + 2] > 0 && board[N - 1][M + 2] < 7))) {
		if (board[N - 1][M + 2] == 99) return status;
		if (board[N - 1][M + 2] > 0 && board[N - 1][M + 2] < 7) {
			for (int i = 0; i < eF; i++) {
				if (attack[i][0] == N - 1 && attack[i][1] == M + 2)  attack[i][2] = 0;
			}
			for (int i = 0; i < eF; i++) {
				attacks(f_board, attack[i]);
				board = mergeBoards(board, f_board); // в теории на этом шаге мы убрали фигуру и ее последствия
			}
		}

		board[N - 1][M + 2] = status; //--| вверх
		move6 = Kn_rec_move(N - 1, M + 2, f_board, board, status - 1, attack, eF);

	}
	equal(board, path_board, 8);
	equal(f_board, figure_board, 8);
	equal(attack, Attack, eF);
	int move7 = -99;
	if (N - 1 < 8 && N - 1 >= 0 && M - 2 < 8 && M - 2 >= 0 && (board[N - 1][M - 2] == 0 || board[N - 1][M - 2] == 99 || (board[N - 1][M - 2] > 0 && board[N - 1][M - 2] < 7))) {
		if (board[N - 1][M - 2] == 99) return status;
		if (board[N - 1][M - 2] > 0 && board[N - 1][M - 2] < 7) {
			for (int i = 0; i < eF; i++) {
				if (attack[i][0] == N - 1 && attack[i][1] == M - 2)  attack[i][2] = 0;
			}
			for (int i = 0; i < eF; i++) {
				attacks(f_board, attack[i]);
				board = mergeBoards(board, f_board); // в теории на этом шаге мы убрали фигуру и ее последствия
			}
		}

		board[N - 1][M - 2] = status;  // |-- вверх
		move7 = Kn_rec_move(N - 1, M - 2, f_board, board, status - 1, attack, eF);

	}
	equal(board, path_board, 8);
	equal(f_board, figure_board, 8);
	equal(attack, Attack, eF);
	int move8 = -99;
	if (N + 1 < 8 && N + 1 >= 0 && M - 2 < 8 && M - 2 >= 0 && (board[N + 1][M - 2] == 0 || board[N + 1][M - 2] == 99 || (board[N + 1][M - 2] > 0 && board[N + 1][M - 2] < 7))) {
		if (board[N + 1][M - 2] == 99) return status;
		if (board[N + 1][M - 2] > 0 && board[N + 1][M - 2] < 7) {
			for (int i = 0; i < eF; i++) {
				if (attack[i][0] == N + 1 && attack[i][1] == M - 2)  attack[i][2] = 0;
			}
			for (int i = 0; i < eF; i++) {
				attacks(f_board, attack[i]);
				board = mergeBoards(board, f_board); // в теории на этом шаге мы убрали фигуру и ее последствия
			}
		}

		board[N + 1][M - 2] = status;  // |-- вниз
		move8 = Kn_rec_move(N + 1, M - 2, f_board, board, status - 1, attack, eF);

	}
	return max(max(max(move1,move2),max(move3,move4)),max(max(move5,move6),max(move7,move8)));
}




int main() {

	int** board = new int* [8];
	for (int i = 0; i < 8; i++) {
		board[i] = new int[8];
	}

	setBoard(board);
	int eF;
	cout << "Type number of enemy figures\n";
	cin >> eF;
	int** attack = new int* [eF];
	for (int i = 0; i < eF; i++) {
		attack[i] = new int[3];
	}
	for (int i = 0; i < eF; i++) {
		cout << "enemy figure " << i + 1 << " info\n";
		attack[i] = ChooseFigure(board);
	}

	for (int i = 0; i < eF; i++) {
		attacks(board, attack[i]);
	}
	int aF;
	cout << "Type number of allied figures\n";
	cin >> aF;
	for (int i = 0; i < aF; i++) {
		cout << "allied figure " << i + 1 << " info\n";
		ChooseAllyFigure(board);
	}

	/*cout << "your figure\n";
	cout << "vertical\n";
	cin >> M;
	cout << "gorizont\n";
	cin >> N;

	cout << "choose figure\n" << "1 pawn; 2 rook; 3 knight(horse); 4 bishop; 5 queen; 6 king\n";
	cin >> F;
	board[M - 1][N - 1] = F;*/
	const int danger = 9;
	const int empty = 0;




	int** path_board = new int* [8];
	for (int i = 0; i < 8; i++) {
		path_board[i] = new int[8];
	}
	setBoard(path_board);

	int* destination = new int[3];
	cout << "Choose destination point\n";
	destination = ChooseDestinationPoint(board);
	//path_board[destination[0]-1][destination[1]-1]=destination[2];
	//delete[] destination;

	cout << endl;
	getBoard(board);

	cout << "\n\npath\n\n";
	int x, y;
choose:
	cin >> y >> x;
	if (board[y - 1][x - 1] == 0 || board[y - 1][x - 1] == 9) board[y - 1][x - 1] = -1;
	else {
		cout << "Another figure already claims this cell. Please choose different coordinates\n\n";
		goto choose;
	}
	getBoard(board);
	cout << "\n\n\n\n\n";
	for (int m = 0; m < 8; m++) {					// рисуем доску
		for (int n = 0; n < 8; n++) {
			cout << "[" << (board[m][n]) << "] ";
		}
		cout << endl;
	}
	int rec=0;
	rec=Kn_rec_move(y - 1, x - 1, board, board, -1, attack, eF);

	

	// оно ищет
	// ура
	// наконецто
	// всего-то пару недель
	bool checking = 0;
	int counter = 0;
	int i = -1;
	for (int t = 0; t < 99; t++) {

		for (int m = 0; m < 8; m++) {
			for (int n = 0; n < 8; n++) {
				//for (int i = 2; i < 5; i++) {

				if (board[n][m] == i) {


					checking = Kn_move(n, m, board, i - 1);


				}

				if (checking) {
					cout << "za " << fabs(i) << " shagov";
					goto end;
				}
				//}
			}

		}	i--;
		cout << "\n\n\n\n\n";
		for (int g = 0; g < 8; g++) {					// рисуем доску
			for (int d = 0; d < 8; d++) {
				cout << "[" << (board[g][d]) << "] ";
			}
			cout << endl;
		}
	}
	cout << " ne nashol puti";
end:
//	//if (checking) {
//	//	cout << "za " << counter << " shagov";
//	//	//goto end;
//	//}
//	//else cout << " ne nashol puti";
	cout << "\n\n rec \n\n" << rec;


	return 0;
}