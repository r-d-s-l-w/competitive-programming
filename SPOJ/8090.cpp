#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int Z; const double pi = acos(-1.0);
    cin >> Z;
    while (Z--)
    {
        double obw, x=0; int d, n;
        cin >> d >> n;
        if (n%2==0) {x=n/2; obw=(d*pi)/n;}
        else {x=n; obw=(d*pi)/(n*2);}
        cout << fixed << setprecision(3) << obw << " " << setprecision(0) << x << endl;
    }
    return 0;
}
