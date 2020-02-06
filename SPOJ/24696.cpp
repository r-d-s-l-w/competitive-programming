#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int z; double r1, r2, r3, a, b, P; const double PI  =3.141592653589793238463;
    cin >> z;
    while (z--)
    {
        cin >> r1 >> r2;
        a=2*r1; b=2*r2;
        r3=(sqrt(a*a+b*b))/2;
        P=((PI*r1*r1)/2)+((PI*r2*r2)/2)+((a*b)/2)-((PI*r3*r3)/2);
        cout << fixed << setprecision(2) << P << endl;
    }
}
