#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int d, m; double n, x, z; string a;
    cin >> d;
    while (d--)
    {
        cin >> n >> a;
        x=(a[0]-48)*36000+(a[1]-48)*3600+(a[3]-48)*600+(a[4]-48)*60+(a[6]-48)*10+(a[7]-48);
        x/=n/1000; x=round(x);
        m=x/60; x-=m*60;
        cout << m << ':';
        if (x<9.5) cout << 0 << round(x) << "\n";
        else cout << round(x) << "\n";
    }
}
