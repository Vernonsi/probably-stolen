#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "Russian");
    double i, sum, n, pr, t, d;
    cin >> n;
    d = 1;
    t = 1 / d;
    sum = 0;
    pr = 1;
    for (i = 1; i <= n; i++)
    {
        sum = sum + t;
        pr = pr * t;
        cout << pr << endl;
        if (i < n)
        {
            d = d + 2;
            t = 1 / d;
            cout << t << " ";
        }
    }
    cout << endl;
    cout << "Сумма=" << sum << endl;
    cout << "Произведение=" << pr << endl;
    return 0;
}