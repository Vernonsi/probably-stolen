//#include <iostream>
//using namespace std;
//
//
////class Identify {
////	int id;
////	const char* pic;
////public:
////	const char* getPic(int n) {
////		switch (n) {
////		case 0: return " ";
////		case 1: return "p";
////		case 2: return "r";
////		case 3: return "kn";
////		case 4: return "b";
////		case 5: return "q";
////		case 6: return "k";
////		case 9: return "x";
////		default: return "problemi y menya aaaaaaaaaaaaaaaaaaa";
////		}
////	}
////};
////class Empty {
////	const int id = 0;
////	const char* pic = " ";
////};
////class Pawn {
////	const int id = 1;
////	const char* pic = "p";
////	void attack(int N/*y*/, int M/*x*/, int** board, int status) { // в процессе
////		if (board[N - 1][M - 1] && board[N - 1][M - 1] == 0) board[N - 1][M - 1] = status;
////		if (board[N - 1][M + 1] && board[N - 1][M + 1] == 0) board[N - 1][M + 1] = status;
////	}
////};
////class Rook {
////	const int id = 2;
////	const char* pic = "r";
////};
////class Knight {
////		const int id = 3;
////		const char* pic = "kn";
////		void attack(int N/*y*/, int M/*x*/, int** board, int status) { // в процессе
////			if (board[N + 2][M + 1] && board[N + 2][M + 1] == 0) board[N + 2][M + 1] = status; //L
////			if (board[N + 2][M - 1] && board[N + 2][M - 1] == 0) board[N + 2][M - 1] = status; //L в другую сторону
////			if (board[N - 2][M - 1] && board[N - 2][M - 1] == 0) board[N - 2][M - 1] = status; // Г в другую сторону
////			if (board[N - 2][M + 1] && board[N - 2][M + 1] == 0) board[N - 2][M + 1] = status; //Г
////			if (board[N + 1][M + 2] && board[N + 1][M + 2] == 0) board[N + 1][M + 2] = status; //--| вниз
////			if (board[N - 1][M + 2] && board[N - 1][M + 2] == 0) board[N - 1][M + 2] = status; //--| вверх
////			if (board[N - 1][M - 2] && board[N - 1][M - 2] == 0) board[N - 1][M - 2] = status; // |-- вверх
////			if (board[N + 1][M - 2] && board[N + 1][M - 2] == 0) board[N + 1][M - 2] = status; // |-- вниз
////		}
////};
////class Bishop {
////	const int id = 4;
////	const char* pic = "b";
////};
////class Queen {
////	const int id = 5;
////	const char* pic = "q";
////};
////class King {
////	const int id = 6;
////	const char* pic = "k";
////};
//
//
//const char* getPic(int n) {
//	switch (n) {
//	case 0: return " ";
//	case 1: return "p"; case 10: return "P";
//	case 2: return "r"; case 20: return "R";
//	case 3: return "h"; case 30: return "H";
//	case 4: return "b"; case 40: return "B";
//	case 5: return "q";	case 50: return "Q";
//	case 6: return "k"; case 60: return "K";
//	case 9: return "x";
//	case -1: return "O";
//	default: return "problemi y menya aaaaaaaaaaaaaaaaaaa";
//	}
//}
//
//
//void getBoard(int** board) {
//	for (int m = 0; m < 8; m++) {					// рисуем доску
//		for (int n = 0; n < 8; n++) {
//			cout << "[" << getPic(board[m][n]) << "] ";
//		}
//		cout << endl;
//	}
//}
//
//void P_attack(int n/*y*/, int m/*x*/, int** board, int status) { // в процессе
//	int N = n - 1, M = m - 1;
//	if (N +1 < 8 && N +1 >= 0 && M -1 < 8 && M -1 >= 0 && board[N + 1][M - 1] == 0) board[N + 1][M - 1] = status;
//	if (N +1 < 8 && N +1 >= 0 && M + 1 < 8 && M + 1 >= 0 && board[N + 1][M + 1] == 0) board[N + 1][M + 1] = status;
//}
//
//void Kn_attack(int n/*y*/, int m/*x*/, int** board, int status) { // в процессе
//	int N = n - 1, M = m - 1;
//	if (N + 2 < 8 && N + 2 >= 0 && M + 1 < 8 && M + 1 >= 0 && board[N + 2][M + 1] == 0) board[N + 2][M + 1] = status; //L
//	if (N + 2 < 8 && N + 2 >= 0 && M - 1 < 8 && M - 1 >= 0 && board[N + 2][M - 1] == 0) board[N + 2][M - 1] = status; //L в другую сторону
//	if (N - 2 < 8 && N - 2 >= 0 && M - 1 < 8 && M - 1 >= 0 && board[N - 2][M - 1] == 0) board[N - 2][M - 1] = status; // Г в другую сторону
//	if (N - 2 < 8 && N - 2 >= 0 && M + 1 < 8 && M + 1 >= 0 && board[N - 2][M + 1] == 0) board[N - 2][M + 1] = status; //Г
//	if (N + 1 < 8 && N + 1 >= 0 && M + 2 < 8 && M + 2 >= 0 && board[N + 1][M + 2] == 0) board[N + 1][M + 2] = status; //--| вниз
//	if (N - 1 < 8 && N - 1 >= 0 && M + 2 < 8 && M + 2 >= 0 && board[N - 1][M + 2] == 0) board[N - 1][M + 2] = status; //--| вверх
//	if (N - 1 < 8 && N - 1 >= 0 && M - 2 < 8 && M - 2 >= 0 && board[N - 1][M - 2] == 0) board[N - 1][M - 2] = status; // |-- вверх
//	if (N + 1 < 8 && N + 1 >= 0 && M - 2 < 8 && M - 2 >= 0 && board[N + 1][M - 2] == 0) board[N + 1][M - 2] = status; // |-- вниз
//}
//
//void R_attack(int n/*y*/, int m/*x*/, int** board, int status) { // в процессе
//	int N = n - 1, M = m - 1;
//	while (N + 1 < 8 && N + 1 >= 0 && M < 8 && M >= 0 && (board[N + 1][M] == 0 || board[N + 1][M] == 9)) {
//		board[N + 1][M] = status; //vniz
//		N++;
//	}
//	N = n - 1, M = m - 1;
//	while (N - 1 < 8 && N - 1 >= 0 && M < 8 && M >= 0 && (board[N - 1][M] == 0 || board[N - 1][M] == 9)) {
//		board[N - 1][M] = status; //vverh
//		N--;
//	}
//	N = n - 1, M = m - 1;
//	while (N < 8 && N >= 0 && M + 1 < 8 && M + 1 >= 0 && (board[N][M + 1] == 0 || board[N][M + 1] == 9)) {
//		board[N][M + 1] = status; // napravo
//		M++;
//	}
//	N = n - 1, M = m - 1;
//	while (N < 8 && N >= 0 && M - 1 < 8 && M - 1 >= 0 && (board[N][M - 1] == 0 || board[N][M - 1] == 9)) {
//		board[N][M - 1] = status; // nalevo
//		M--;
//	}
//}
//
//void B_attack(int n/*y*/, int m/*x*/, int** board, int status) {
//	int N = n - 1, M = m - 1;
//	while (N + 1 < 8 && N + 1 >= 0 && M + 1 < 8 && M + 1 >= 0 && (board[N + 1][M + 1] == 0 || board[N + 1][M + 1]==9)) {
//		board[N + 1][M + 1] = status; // naprovo-vniz
//		N++;
//		M++;
//	}
//	N = n - 1, M = m - 1;
//	while (N + 1 < 8 && N + 1 >= 0 && M - 1 < 8 && M - 1 >= 0 && (board[N + 1][M - 1] == 0 || board[N + 1][M - 1] == 9)) {
//		board[N + 1][M - 1] = status; // nalevo-vniz
//		N++;
//		M--;
//	}
//	N = n - 1, M = m - 1;
//	while (N - 1 < 8 && N - 1 >= 0 && M + 1 < 8 && M + 1 >= 0 && (board[N - 1][M + 1] == 0 || board[N - 1][M + 1] == 9)) {
//		board[N - 1][M + 1] = status; // naprovo-vverh
//		N--;
//		M++;
//	}
//	N = n - 1, M = m - 1;
//	while (N - 1 < 8 && N - 1 >= 0 && M - 1 < 8 && M - 1 >= 0 && (board[N - 1][M - 1] == 0 || board[N - 1][M - 1] == 9)) {
//		board[N - 1][M - 1] = status; // nalevo-vverh
//		N--;
//		M--;
//	}
//
//}
//
//void Q_attack(int n/*y*/, int m/*x*/, int** board, int status){
//	R_attack(n, m, board, 9);
//	B_attack(n, m, board, 9);
//}
//
//
//void K_attack(int n/*y*/, int m/*x*/, int** board, int status) {
//	int N = n - 1, M = m - 1;
//	if (N - 1 < 8 && N - 1 >= 0 && M - 1 < 8 && M - 1 >= 0 && board[N - 1][M - 1] == 0) board[N - 1][M - 1] = status;
//	if (N - 1 < 8 && N - 1 >= 0 && M < 8 && M >= 0 && board[N - 1][M] == 0) board[N - 1][M] = status;
//	if (N - 1 < 8 && N - 1 >= 0 && M + 1 < 8 && M + 1 >= 0 && board[N - 1][M + 1] == 0) board[N - 1][M + 1] = status;
//	if (N < 8 && N >= 0 && M - 1 < 8 && M - 1 >= 0 && board[N][M - 1] == 0) board[N][M - 1] = status;
//	if (N < 8 && N >= 0 && M + 1 < 8 && M + 1 >= 0 && board[N][M + 1] == 0) board[N][M + 1] = status;
//	if (N + 1 < 8 && N + 1 >= 0 && M + 1 < 8 && M + 1 >= 0 && board[N + 1][M - 1] == 0) board[N + 1][M - 1] = status;
//	if (N + 1 < 8 && N + 1 >= 0 && M < 8 && M >= 0 && board[N + 1][M] == 0) board[N + 1][M] = status;
//	if (N + 1 < 8 && N + 1 >= 0 && M + 1 < 8 && M + 1 >= 0 && board[N + 1][M + 1] == 0) board[N + 1][M + 1] = status;
//}
//
//int* ChooseFigure(int **board){
//	int N, M, F;
//check:	
//	cout << "vertical\n";
//	cin >> M;
//	cout << "gorizont\n";
//	cin >> N;
//	cout << "choose figure\n" << "1 pawn; 2 rook; 3 knight(horse); 4 bishop; 5 queen; 6 king\n";
//	cin >> F;
//	if (board[M - 1][N - 1] != 0 && board[M - 1][N - 1] != 9) {
//		cout << "Another figure already claims this cell. Please choose different coordinates\n\n";
//		goto check;
//	}
//	board[M - 1][N - 1] = F; 
//	int* F_info = new int[3];
//	F_info[0] = M;
//	F_info[1] = N;
//	F_info[2] = F;
//	return F_info;
//}
//int* ChooseAllyFigure(int** board) {
//	int N, M, F;
//check:
//	cout << "vertical\n";
//	cin >> M;
//	cout << "gorizont\n";
//	cin >> N;
//	cout << "choose figure\n" << "1 pawn; 2 rook; 3 knight(horse); 4 bishop; 5 queen; 6 king\n";
//	cin >> F;
//	if (board[M - 1][N - 1] != 0 && board[M - 1][N - 1] != 9) {
//		cout << "Another figure already claims this cell. Please choose different coordinates\n\n";
//		goto check;
//	}
//	board[M - 1][N - 1] = F*10;
//	int* F_info = new int[3];
//	F_info[0] = M;
//	F_info[1] = N;
//	F_info[2] = F;
//	return F_info;
//}
//
//int* ChooseDestinationPoint(int** board) {
//	int N, M, F=-1;
//check:
//	cout << "vertical\n";
//	cin >> M;
//	cout << "gorizont\n";
//	cin >> N;
//
//	if (board[M - 1][N - 1] != 0 && board[M - 1][N - 1] != 9) {
//		cout << "Another figure already claims this cell. Please choose different coordinates\n\n";
//		goto check;
//	}
//	board[M - 1][N - 1] = F;
//	int* F_info = new int[3];
//	F_info[0] = M;
//	F_info[1] = N;
//	F_info[2] = F;
//	return F_info;
//}
//
//void attacks(int** board,int* F) {
//	switch (F[2]) {
//	case 1: P_attack(F[0], F[1], board, 9);
//		break;
//	case 2: R_attack(F[0], F[1], board, 9);
//		break;
//	case 3: Kn_attack(F[0], F[1], board, 9);
//		break;
//	case 4: B_attack(F[0], F[1], board, 9);
//		break;
//	case 5: Q_attack(F[0], F[1], board, 9);
//		break;
//	case 6: K_attack(F[0], F[1], board, 9);
//		break;
//	default: break;
//	}
//}
//
//void setBoard(int** board) {       // делаем пустую доску
//	for (int m = 0; m < 8; m++) { 
//		for (int n = 0; n < 8; n++) {
//
//			board[m][n] = 0;
//		}
//	}
//}
//
//class YourFigure {
//	int id;
//public:
//	YourFigure(int i) {
//		id = i;
//	}
//
//	void attacks(int** board, int* F,int counter) {
//		switch (F[2]) {
//		case 1: P_attack(F[0], F[1], board, counter);
//			break;
//		case 2: R_attack(F[0], F[1], board, counter);
//			break;
//		case 3: Kn_attack(F[0], F[1], board, counter);
//			break;
//		case 4: B_attack(F[0], F[1], board, counter);
//			break;
//		case 5: Q_attack(F[0], F[1], board, counter);
//			break;
//		case 6: K_attack(F[0], F[1], board, counter);
//			break;
//		default: break;
//		}
//	}
//
//
//};
//
////int main() {
////
////	int **board = new int*[8];
////	for (int i = 0; i < 8; i++) {
////		board[i] = new int[8];
////	}
////	
////	setBoard(board);
////	int eF;
////	cout << "Type number of enemy figures\n";
////	cin >> eF;
////	int** attack = new int*[eF];
////	for (int i = 0; i < eF; i++) {
////		attack[i] = new int[3];
////	}
////	for (int i = 0; i < eF; i++) {
////		cout << "enemy figure " << i + 1 << " info\n";
////		attack[i]=ChooseFigure(board);
////	}
////	
////	for (int i = 0; i < eF; i++) {
////		attacks(board,attack[i]);
////	}
////	int aF;
////	cout << "Type number of allied figures\n";
////	cin >> aF;
////	for (int i = 0; i < aF; i++) {
////		cout << "allied figure " << i + 1 << " info\n";
////		ChooseAllyFigure(board);
////	}
////
////	/*cout << "your figure\n";
////	cout << "vertical\n";
////	cin >> M;
////	cout << "gorizont\n";
////	cin >> N;
////
////	cout << "choose figure\n" << "1 pawn; 2 rook; 3 knight(horse); 4 bishop; 5 queen; 6 king\n";
////	cin >> F;
////	board[M - 1][N - 1] = F;*/
////	const int danger = 9;
////	const int empty = 0;
////
////
////	
////
////	int** path_board = new int* [8];
////	for (int i = 0; i < 8; i++) {
////		path_board[i] = new int[8];
////	}
////	setBoard(path_board);
////	
////	int*destination = new int[3];
////	cout << "Choose destination point\n";
////	destination=ChooseDestinationPoint(board);
////	path_board[destination[0]-1][destination[1]-1]=destination[2];
////	delete[] destination;
////	
////	cout << endl;
////	getBoard(board);
////	
////	cout << "\n\npath\n\n";
////	getBoard(path_board);
////
////	
////}