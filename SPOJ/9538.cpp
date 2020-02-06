#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t, a, x, b, y, odl;
    cin >> t;
    while (t--)
    {
        cin >> a >> x >> b >> y;
        if (x>y) odl=x-y; else odl=y-x;
        if (a>b)
        {
            if (odl%3==1) cout << 0 << endl;
            else cout << 1 << endl;
        }
        else
        {
            if (odl%3==1) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}
