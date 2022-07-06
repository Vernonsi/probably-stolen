#ifndef CHECK_CPP
#define CHECK_CPP


#include <iostream>
#include <string>

using namespace std;

bool CheckLength(string str) // проверка на длину числа
{
	if (str.length() <= 30) return true;
	return false;
}
bool CheckLengthI(string str) // проверка на длину числа
{
	if (str.length() <= 10) return true;
	return false;
}

bool CheckDigitD(string str) // проверка на буквы и лишние символы
{
	int d = 0;
	int x = 0;
	int m = 0;
	if (str[0] == '-') m++;
	if ((str[1] == '.' && str[0]=='-') || (str[1] == '-' && str[0] == '.')) return false;
	for (int i = 0; i < str.length() + 1; i++) {
		if (d >= 2) {
			return false;
		}
		if (isdigit(str[i])) x++;
		if (i != 0) {
			if (str[i] == '-') return false;
		}
		if (str[i] == '.') {
			d++;
		}
		}
	if (x == str.length() - d - m) return true;
	return false;
}

bool CheckBoolD(double s) // проверка уже существующего числа
{
	string str = to_string(s);
	if (CheckDigitD(str) && CheckLength(str)) return true;
	return false;
}

double CheckD(string what) { // проверка вводимого дейстительное числа
	string str;
	while (true) {

		cout << "input " << what << ": ";
		cin >> str;

		if(CheckDigitD(str) && CheckLength(str)) return stod(str);

		else {
			cout << "invalid input" << endl;
		}
	}
}
bool CheckDigitI(string str) // проверка существующего целого числа
{
	for (int i = 0; i < str.length(); i++) {
		if (str[0] == '-' || str[0] == '+') {
			continue;
		}
		if (isdigit(str[i])) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}
int Sign(string str) { // проверка на знак
	if (str[0] == '-') return -1;
	return 1;
}


int CheckInt(string what) {
	while (true) {
		string str;
		cout << "input " << what << ": ";
		cin >> str;
		if (CheckDigitI(str) && CheckLengthI(str) && Sign(str) == 1) {
			return stoi(str);
		}
		cout << "invalid input" << endl;
	}
}
int CheckIntZ(string what) {
	while (true) {
		string str;
		cout << "input " << what << ": ";
		cin >> str;
		if (CheckDigitI(str) && CheckLengthI(str) && Sign(str) == 1 && stoi(str) != 0) {
			return stoi(str);
		}
		cout << "invalid input" << endl;
	}
}

double CheckDPosit(string what) { // проверка на положительное действительное число
	string str;
	while (true) {

		cout << "input " << what << ": ";
		cin >> str;
		if (str[0] == '-') {
			cout << "invalid input" << endl;
			continue;
		}
		if (CheckDigitD(str) && CheckLength(str) && Sign(str) == 1) {
			return stod(str);
		}
		else {
			cout << "invalid input" << endl;
		}
	}
}

double CheckDNegat(string what) { // проверка на отрицательное действительное число
	string str;
	while (true) {

		cout << "input " << what << ": ";
		cin >> str;

		if (CheckDigitD(str) && CheckLength(str) && Sign(str) == -1) return stod(str);

		else {
			cout << "invalid input" << endl;
		}
	}
}


#endif // !CHECK_CPP