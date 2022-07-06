
#include <iostream>
#include <math.h>
using namespace std;

int main()
{setlocale (0, "Russian");
	double x, y;
	cin >>x>> y;

	if ((-3*x+3*y+1) == 0) cout << ("Точка находится на прямой") << endl;
	if (((pow(x,2)+pow(y-2,2)) == 1)) cout << ("Точка находится на окружжности") << endl;
	if ((pow(x-2,2)-2) == y) cout << ("Точка находится на параболе") << endl;

	if ((pow(x - 2, 2) - 2) < y) cout << ("В области параболы")<< endl;
	if ((pow(x - 2, 2) - 2) > y) cout << ("Не в области параболы") << endl;

	if (((pow(x, 2)) + pow(y - 2, 2)) > 1) cout << ("Не в области окружности") << endl;
	if (((pow(x, 2)) + pow(y - 2, 2)) < 1) cout << ("В области окружности") << endl;

	if ((-3 * x + 3 * y + 1) > 0) cout << ("Точка находится над прямой") << endl;
	if ((-3 * x + 3 * y + 1) < 0) cout << ("Точка находится под прямой") << endl;


	return 0;
	
	
}
