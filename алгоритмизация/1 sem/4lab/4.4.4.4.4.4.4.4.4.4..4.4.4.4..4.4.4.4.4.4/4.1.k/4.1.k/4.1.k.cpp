#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "Russian");
    double i, sum, n, pr, t, d;
    cin >> n;
    n = n + 1;
    d = 1;
    t = 1 / d;
    sum = -1;
    pr = 1;
    for (i = 1; i <= n; i++)
    {
        sum = sum + t;
        pr = pr * t;
        
        if (i < n)
        {
            d = d *i;
            t = 1 / d;
          
        }
    }
    cout << endl;
    cout << "Сумма=" << sum << endl;
    cout << "Произведение=" << pr << endl;
    return 0;
}