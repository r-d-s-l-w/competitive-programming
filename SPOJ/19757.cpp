#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long long int d, k, n, x;
    cin >> d;
    while (d--)
    {
        cin >> k >> n;
        if (k==1) cout << n << endl;
        else
        {
            x=n-1;
            for (int i=1; i<k; i++) x*=n;
            cout << x << endl;
        }
    }
    return 0;
}
