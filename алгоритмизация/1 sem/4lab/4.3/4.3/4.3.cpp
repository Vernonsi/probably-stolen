#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    setlocale(0, "Russian");
    double x, i, h, z, sum,arc;
    cout << "Введите х"<< endl;
    cin >> x;
    cout << "Введите точность " << endl;
    cin >> h;
    i = 0;
    sum = 0;
    z = 0;
    while (abs(z) <= h)
    {
        i++;
        z = pow(-1, i) * (pow(x, 2 * i + 1) / (2 * i + 1));
        cout << z << endl;
        sum = sum + z;
    } 
    cout << endl;
    cout << sum << endl;
    arc = atan(x);
    cout << endl;
    cout << arc;
 
    return (0);
}