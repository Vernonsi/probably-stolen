#include <iostream>
class a {
public:
    double z, x, zz, g;

    long double fact(double N)
    {
        if (N < 0)
            return 0;
        if (N == 0)
            return 1;
        else
            return N * fact(N - 1);
    }

    void sinx( double x) {
       
       /* std::cin >> x;*/
        if (x > 0) {
            double  z = x;
            double   g = x * 0.001;
            double    zz = 0;
            for (int n = 0; abs(z) >= g; n++) {
                z = pow(-1, n) * pow(x, 2 * n + 1) / fact(2 * n + 1);
                zz = zz + z;
            }
            std::cout << std::endl << zz << std::endl;
            std::cout << "sin " << sin(x);
        }
        else std::cout << "Invalid number";
    }
};