#include <iostream>
using namespace std;
int main()
{
    double x, y;
    x = -5;
    while (x<=5) {
        y = pow(x, 2) - 3 * x + 4;
        cout << y << endl;
        x = x + 0.5;
    }
    return 0;
}
