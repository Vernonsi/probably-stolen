#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "Russian");
    double  sum, n, pr, t, d;
    int i;
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
            d = d + 1;
            t = 1 / d;
            if ((i % 2) != 0) t = -t;
            cout << t << " ";
        }
    }
    cout << endl;
    cout << "Сумма=" << sum << endl;
    cout << "Произведение=" << pr << endl;
    return 0;
}