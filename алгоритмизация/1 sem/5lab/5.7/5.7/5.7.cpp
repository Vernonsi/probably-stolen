
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;
int main()
{
    setlocale(0, "Russian");
    double x1,x2,x, y1, y2, y3, dx, a, b;
    cout << "Введите x1" <<endl;
    cin >> x1;
    cout << "Введите x2" << endl;
    cin >> x2;
    cout << "Введите  шаг" << endl;
    cin >> dx;
    cout << "Введите a" << endl;
    cin >> a;
    cout << "Введите b" << endl;
    cin >> b;
    cout << setw(15) << left << "X" << "  |" << setw(15) << left << "Y1" << "  |" << setw(15) << left << "Y2" << "  |" << setw(15) << left << "Y3" << "  |" << endl;
    cout << setw(15) << left << "------------------" << setw(15) << left << "------------------" << setw(15) << left << "------------------" << setw(15) << left << "------------------" << endl;
    for (x = x1; x < x2; x = x + dx)
    {
      

        if (x <= 0) y1 = log(sin(a * x) + M_PI / 2);
        else y1 = log(M_PI + b * pow(x, 2)) - log(2 / (1 + x));
       

        if (x <= 0) y2 = a * cos(b);
        else y2 = a - pow(b, x);
      

        if (x <= -1) y3 = sqrt(a * abs(x + 1));
        else y3 = (b / sqrt(2)) - sqrt(pow(b, 2) / (1 + pow(x, 2)));
        cout << setw(15) << left << x << "  |" << setw(15) << left << y1 << "  |" << setw(15) << left << y2 << "  |" << setw(15) << left << y3 << "  |" << endl;
    }
    return 0;
}   
