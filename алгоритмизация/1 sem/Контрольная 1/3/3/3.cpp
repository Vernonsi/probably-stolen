#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    setlocale(0, "Russian");
    double x, y1, y2;
    int n;
    cout << "Введите x"<< endl;
    cin >> x;
    if (x < 0 || x == 5) {
        cout << "Нет решений"<<endl;
        return 0;
    }
    cout << "Введите номер функции"<< endl;
    cin >> n;
    if (n != 1 && n != 2) {
        cout << "Неверный номер функции";
        return 0;
    }
    switch (n) {
    case(1) : y1 = (pow(sin(x) + (1 / 2) * cos(x), 3 / 2));
        cout << y1;
    case(2):   y2 = (sqrt(x) * exp(fabs(x))) / (x - 5);
        cout << y2;
    }
    return 0;
}