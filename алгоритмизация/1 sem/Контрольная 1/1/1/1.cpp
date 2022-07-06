#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "Russian");
    double a;
    cin >> a;
    if (a >= -1 && a <= 1) cout << "Число принадлежит промежутку [-1;1]";
    else cout << "Число не принадлежит промежутку [-1;1]";
    return 0;
}
