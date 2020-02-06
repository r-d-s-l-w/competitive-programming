#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long long int t, a, b, m; string x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y; m=1; a=0; b=0;
        for (int i=0; i<x.length(); i++)
        {
            a+=(x[i]-48)*m;
            m*=10;
        }
        m=1;
        for (int i=0; i<y.length(); i++)
        {
            b+=(y[i]-48)*m;
            m*=10;
        }
        a>b?cout<<a<<"\n":cout<<b<<"\n";
    }
}
