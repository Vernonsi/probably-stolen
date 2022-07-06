#include "Classes.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	Gift gift("data.txt");
	gift.Outer();
	gift.Sort();
	gift.Outer();
	gift.Search();
}
