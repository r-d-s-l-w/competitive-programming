#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    double a, b, x, h, H, c, area; int k;
    cin >> k;
    while (k--)
    {
        cin >> a >> b;
        c=(a+b)/2;
        if (a>b) x=(a-b)/2;
        else x=(b-a)/2;
        H=c*c-x*x;
        area=c*sqrt(H);
        cout << fixed << setprecision(2) << area << endl;

    }
    return 0;
}
