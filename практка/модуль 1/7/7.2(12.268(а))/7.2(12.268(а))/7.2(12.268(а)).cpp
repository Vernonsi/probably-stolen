#include <iostream>

#include <iomanip>

#include <ctime>
using namespace std;

int main()

{

	int i, j, a, k;

	int A[7][7];

	setlocale(LC_ALL, "Russian"); // Русский язык в консоли

	srand(time(0));

	for (i = 0; i < 7; i++)

	{

		for (j = 0; j < 7; j++)

		{

			A[i][j] = rand() % 100-50;

			std::cout << std::setw(5) << A[i][j];

		}

		std::cout << std::endl;

	}

	cout << endl;
	int* proceed = new int[7];
	int max = fabs(A[0][0]);
	for (i = 0; i < 7; i++)
	{
		max = A[0][i];
		for (j = 0; j < 7; j++) {
			if (fabs(A[j][i]) > fabs(max)) max = A[j][i];
		}
		proceed[i] = max;
		cout << setw(5) << proceed[i];
	}


}