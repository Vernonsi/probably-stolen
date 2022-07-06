#include <iostream>

#include <iomanip>

#include <ctime>
using namespace std;

int main()

{

	int i, j, a, k;

	int A[7][7];

	setlocale(LC_ALL, "Russian"); // Русский язык в консоли

	srand(static_cast<unsigned int>(time(0)));

	for (i = 0; i < 7; i++)

	{

		for (j = 0; j < 7; j++)

		{

			A[i][j] = rand() % 20;

			std::cout << std::setw(5) << A[i][j];

		}

		std::cout << std::endl;

	}


	for (i = 0; i < 7; i++)

	{

		for (j = 0; j < 7; j++)

		{
			int g = A[i][j];
			while (g > 9) {
				g = g % 10;
			}
			
			if (g == 3) cout << "Элемент, оканчивающийся на 3, находится по координатам " << i + 1 << " " << j + 1 << endl;
			if (A[i][j]==0) cout << "Элемент, равный 0, находится по координатам " << i + 1 << " " << j + 1 << endl;
		}


	}
}