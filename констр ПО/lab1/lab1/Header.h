#include <iostream>
using namespace std;

class sinx {


public:
    /*double fact(double n) {
        double res = 1;
        for (int i = 1; i <= n; i++) 
            res = res * i;
        return res;
    }*/

   long double fact(long double N)
    {
        if (N < 0)
            return 0;
        if (N == 0)
            return 1;
        else
            return N * fact(N - 1);
    }

 

   void sins(double x) {
       double z = x, zz = 0;
       const double g = x * 0.001;
        if (x > 0) {
            for (long double n = 0; abs(z) >= g; n++) {
                z = pow(-1, n) * pow(x, 2 * n + 1) / fact(2 * n + 1);

                zz = zz + z;
            }
            cout << endl << zz << endl;
            cout << "sin " << sin(x);
        }
        else cout << "Invalid number";
    }
};