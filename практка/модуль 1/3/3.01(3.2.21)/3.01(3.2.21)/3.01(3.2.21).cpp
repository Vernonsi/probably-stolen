#include <iostream>
using namespace std;

int main() {
	setlocale(0, "Ru");
	int day = 0;
	int length = 0;
	for (int i = 2; i < 42; i += 2) {
		length += i;
		day++;
	}
	cout << "Спортсмен пробежал " << length << "км за " << day << " дней\n";
	
}