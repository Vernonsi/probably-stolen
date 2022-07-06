#include <iostream>
using namespace std;
int main()
{
    int n, div = 2;
    cout << "N = ";
    cin >> n;
    cout << n << " = 1";
    while (n > 1)
    {
        while (n % div == 0)
        {
            cout << " * " << div;
            n = n / div;
        }
        div++;
    }
}