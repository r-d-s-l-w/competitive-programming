#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, x, maks, y, wzor, xd;
    cin >> t;
    while (t--)
    {
        maks=0; wzor=0; xd=1;
        cin >> n;
        if (n==1) {cin >> y; cout << 1 << endl;}
        else {
        cin >> y; n--;
        while (n--)
        {
            cin >> x;
            if (x-y==wzor) xd++;
            else {wzor=x-y; if (xd>maks) maks=xd; xd=2;}
            y=x;
        }
        if (xd>maks) maks=xd;
        cout << maks << endl;}
    }
}
