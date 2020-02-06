#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int t, n; long double k, x, a, b, c, p, s;
    cin >> t;
    while (t--)
    {
        x=0;
        cin >> n >> k;
        while (n--)
        {
            cin >> a >> b >> c;
            p=(a+b+c)/2;
            if (p*(p-a)*(p-b)*(p-c)<0) x+=0;
            else x+=sqrt(p*(p-a)*(p-b)*(p-c));
        }
        s=round((x*k)/10);
        cout << fixed << setprecision(0) << s << endl;
    }
    return 0;
}
