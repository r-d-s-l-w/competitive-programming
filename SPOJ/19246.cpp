#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long long int t, p, k, x; string n;
    cin >> t;
    while (t--)
    {
        k=1; x=0;
        cin >> p >> n;
        for (int i=n.length()-1; i>=0; i--)
        {
            x+=(n[i]-48)*k;
            x%=1010101;
            k%=1010101;
            k*=p;
        }
        cout << x << "\n";
    }
}
