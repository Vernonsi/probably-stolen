#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "Russian");
    int i, sum, n, pr, t;
    cin >> n;
    t =2;
    sum = 0;
    pr = 1;
    for (i = 1; i <= n; i++)
    {
        sum = sum + t;
        pr = pr * t;
        cout << pr << endl;
        if (i < n)
        {
            t = t + 2;
            cout << t << " ";
        }
    }
    cout << endl;
    cout << "Сумма=" << sum << endl;
    cout << "Произведение=" << pr << endl;
    return 0;
}