﻿//#include <iostream>
//using namespace std;
//
//int main() {
//	setlocale(0, "Russian");
//	int n;
//	cout << "Введите количество дней ";
//	cin >> n;
//	double* stock = new double[n];
//	for (int i = 0; i < n; i++) {
//		cout << "Стоимость в " << i+1 << " день "; 
//		cin >> stock[i];
//	}
//}

#include <iostream>
#include <iomanip>

using namespace std;


double max(double a, double b) {
	return (a > b) ? a : b;
}

double max_crossing_sum(double arr[], int low, int mid, int length) {
	double sum = 0;
	double leftpartsum = -1;
	for (int i = mid; i >= low; i--) {
		sum = sum + arr[i];
		if (sum > leftpartsum)
			leftpartsum = sum;
	}

	sum = 0;
	double rightpartsum = -1;
	for (int i = mid + 1; i <= length; i++) {
		sum = sum + arr[i];
		if (sum > rightpartsum)
			rightpartsum = sum;
	}

	return leftpartsum + rightpartsum;
}

double max_subarray_sum(double arr[], int low, int length)
{
	int mid;
	if (low == length) {
		return arr[low];
	}

	mid = (low + length) / 2;

	return max(max(max_subarray_sum(arr, low, mid), max_subarray_sum(arr, mid + 1, length)), max_crossing_sum(arr, low, mid, length));
}

//// Можно не использовать метод разделяй и властвуй вовсе
//void find_boundaries(double* arr, int length) {
//	int start = 0, end = 0, curr_max = 0, prev_max = 0, start_o = 0;
//	for (int i = 0; i < length; ++i) {
//		curr_max += arr[i];
//		if (curr_max < 0) {
//			start = i + 1;
//			curr_max = 0;
//		}
//		else if (curr_max > prev_max) {
//			end = i;
//			start_o = start;
//			prev_max = curr_max;
//		}
//	}
//
//	cout << "Купить в день: " << start_o + 1 << endl;
//	cout << "Продать в день: " << end + 2 << endl;
//}



int main() {
	setlocale(LC_ALL, "Russian");

	int i, d;
	cout << "Введите количество дней: "; // вводим вводим
	cin >> d;
	double* stock = new double[d];

	for (i = 0; i < d; i++) {
	value:
		cout << "Введите цену в " << i + 1 << " день" << ": ";
		cin >> stock[i];
	}
	cout << "\n";
	int n = d - 1;  

	double* a = new double[n]; // второй ряд с изменением цены
	for (i = 1; i < d; i++) {
		a[i - 1] = stock[i] - stock[i - 1];
	}

	for (int i = 0; i < d; i++) {
		cout << setw(10) << stock[i];
	}
	cout << endl;
	cout << setw(10) << " ";
	for (int i = 0; i < n; i++) {
		cout << setw(10) << a[i];

	}
	double result = max_subarray_sum(a/*это массив*/, 0, n - 1/*это размер массива*/); // и это все?

	cout << "\nМаксимальная выручка: " << result << endl;
	//find_boundaries(a, n);

	return 0;
}