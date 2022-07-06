#include <iostream>
using namespace std;
int main()
{
    double x, y;
    for (x = -5; x <= 5; x = x + 0.5) {
        y = pow(x, 2) - 3 * x + 4;
        cout << y << endl;
    }
    return 0;
}
