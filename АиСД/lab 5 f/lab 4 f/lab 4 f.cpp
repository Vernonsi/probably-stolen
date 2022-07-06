//в числе должно быть не более 6 простых множителей
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int factorial(int n) {  //факториал
	int res = 1;
	for (int i = 2; i <= n; i++) {
		res *= i;
	}
	return res;
}
 
int factors_size(int n) { //размер факториала
	int count = 0;
	int n_copy = n;
	for (int i = 2; i < n; i++) {
		if (n_copy % i == 0) {
			n_copy = n_copy / i;
			i--;
			count++;
		}
		if (n_copy == 1) break;
	}
	return count;
}

int factors_versions(int n) { // количество  производных (всего)
	int last = 1;
	int res = 1;
	for (int i = n; i > 2; i--) {
		res = res + ((factorial(i)) / ((factorial((i - 2))) * 2)) * last;
		last = last * ((factorial(i)) / ((factorial(i - 2)) * 2));
	}
	return res;
}

void start_array(int l, int c, long double** ar, int num) {
	int n = num;
	int k = 2;
	for (int i = 1; i < l; i++) // занулили все
	{
		for (int k = 0; k < c; k++)
		{
			ar[i][k] = 0;
		}
	}
	for (int i = 0; i < c; i++)
	{
		if (n % k == 0) { // анти факториал?(находим производные)
			ar[0][i] = k;
			n = n / k;
		}
		else {
			i--;
			k++;
		}
	}
}

void avto(long double** ar, int l_tek, int l_next, int  st_tek, int st_next, int st) {
	for (int i = 0; i < st; i++) {
		if (i != st_tek && i != st_next) {
		
				ar[l_tek][i] = ar[l_next][i]; // n+1
			
		}
	}
}

void funct(long double** array, int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; i++) { //j это следующее i (n)
			for (int k = 0; k < m; k++)
			{
				for (int d = k + 1; d < m; d++) //d это следующее k (m)
				{
					if (j < n &&  i < n) { // не вышли за границы массива
						if (array[j][0] == 0) { // в след  n первый 0
							if (array[i][d] != 0) { // текущий n след m не 0
								if (array[i][k] != 0) {// текущий n текущий m не 0
									array[j][k] = array[i][k] * array[i][d]; // след n  m*(m+1)
									array[j][d] = 0;//n+1 m+1=0
									avto(array, j, i, k, d, m);
									j++;// скипаем нулевое j?
								}
							}
						}
					}
					else { i = n; j = n; k = m; d = m; } //заканчиваем
				}
			}
		}
	}
}

void zero(long double** array, int n, int m) { // нули в n-ной ячейке
	for (int i = 0; i < m; i++) {
		array[n][i] = 0;
	}
}


void sort(long double** array, int n, int m) { // сортировка по убыванию?
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			for (int d = k + 1; d < m; d++)
			{
				if (k != d && array[i][k] < array[i][d]) {
					int temp = array[i][k];
					array[i][k] = array[i][d];
					array[i][d] = temp;
				}
			}
		}

	}
	int count = 0;
	for (int i = 1; i < n; i++)
	{
		for (int k = i + 1; k < n; k++)
		{
			for (int d = 0; d < m; d++)
			{
				if (array[i][d] == array[k][d]) {
					count++;
				}
			}
			if (count == m) { zero(array, k, m); }
			count = 0;
		}
	}
}
//void sort2(long double** array, int n, int m){ //если id==kd то kd обнуляют, т.е. убирает одинаковые комбинации
//	int count = 0;
//	for (int i = 1; i < n; i++)
//	{
//		for (int k = i + 1; k < n; k++)
//		{
//			for (int d = 0; d < m; d++)
//			{
//				if (array[i][d] == array[k][d]) {
//					count++;
//				}
//			}
//			if (count == m) { zero(array, k, m); }
//			count = 0;
//		}
//	}
//}



int main() {
	int number;
	cin >> number;
	int size_c = factors_size(number);
	int size_l = factors_versions(size_c);
	//cout << size_c << endl;
	//cout << size_l;
	long double** array = new long double* [size_l];
	for (int i = 0; i < size_l; i++)
	{
		array[i] = new long double[size_c];
	}
	start_array(size_l, size_c, array, number);

	funct(array, size_l, size_c);

	sort(array, size_l, size_c);

	//sort2(array, size_l, size_c);

	for (int i = 0; i < size_l; i++)
	{
		if (array[i][0] != 0)cout << endl;
		for (int k = 0; k < size_c; k++)
		{

			if (array[i][k] != 0) {
				cout << array[i][k] << "  ";
			}
		}
	}
	cout << endl;
	system("pause");
	return 0;
}