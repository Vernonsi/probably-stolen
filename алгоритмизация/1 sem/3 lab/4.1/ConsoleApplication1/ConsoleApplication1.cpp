
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    setlocale(0, "Russian");
    int a, a1, a2, a3, a4, pr,g;
    cin >> a;
    if (a <= 0) {
        cout << "Не натуральное число";
        return 0;
    }
    a1 = a / 1000;                                //тысячи
    if ((a1 <= 0) || (a1 >=  10)) {
        cout << "Не четырехзначное число";
    return 0;
}
    a2 = a / 100-a1*10;                           //сотни
    a3 = a/10-a1*100-a2*10;                       //десятки
    a4 = a-a1*1000-a2*100-a3*10;                  //единицы
    cout << a1 << endl;
    cout << a2 << endl;
    cout << a3 << endl;
    cout << a4 << endl;
    pr = a1 * a2 * a3 * a4;
    if ((a1 == a2) && (a1==a3) && (a1==a4))
        cout << "Цифры одинаковые"<< endl;
    else cout << "Цифры разные" << endl;
        

    if (a>pr)
        cout << a << " Больше произведения его цифр" << endl;
    else                                                                //zachem ya sdelal pervoe
        cout << a << " Меньше произведения его цифр" << endl;
    return 0;
}

