
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double x, y,z,y_v_korne,verh1,verh2,niz1,niz2;
    cin >> x>> y;
    y_v_korne = pow(x, 1 / 7.0);
    if (x < 5)
        verh1 = x;
    else verh1 = 5;
    cout << verh1<<" v1"<<endl;
    if ( y > 10)
        verh2 =y;
    else verh2 = 10;
    cout << verh2 <<" v2"<< endl;
    if (verh2 > verh1)
        verh1 = verh2;
    cout << verh2 <<" V"<< endl;
    if (x < 10)
        niz1 = x;
    else niz1 = 10;
    cout << niz1 << " n1"<< endl;
    if (y < y_v_korne)
        niz2 = y;
    else niz2 = y_v_korne;
    cout << niz2 << " n2"<< endl;
    if (niz2 > niz1)
        niz1 = niz2;
    cout << niz1 << " N" << endl;
    z = verh1 / niz1;
    cout << z;
    return 0;
}

