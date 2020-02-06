#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double xa, ya, xb, yb, xc, yc, a, b, c, p;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    a=sqrt((xa*xa-2*xa*xb+xb*xb)+(ya*ya-2*ya*yb+yb*yb));
    b=sqrt((xb*xb-2*xb*xc+xc*xc)+(yb*yb-2*yb*yc+yc*yc));
    c=sqrt((xa*xa-2*xa*xc+xc*xc)+(ya*ya-2*ya*yc+yc*yc));
    p=(a+b+c)/2;
    cout << fixed << setprecision(2) << (a*b*c)/(4*sqrt(p*(p-a)*(p-b)*(p-c))) << endl;
    return 0;
}
