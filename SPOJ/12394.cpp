#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long long int k, n, x, y, m;
    cin >> k;
    while (k--)
    {
        cin >> n;
        x=2; y=1; m=n;
        while (m!=1)
        {
        if (m%2==1&&y+x<=n) y+=x;
        x*=2; m/=2;
        }
        cout << y << endl;
    }
    return 0;
}
