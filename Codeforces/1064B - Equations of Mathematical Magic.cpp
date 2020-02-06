#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, t;
    cin >> t;
    while (t--)
    {
        cin >> a;
        int suma=1;
        for (int i = 0; i < 32; i++)
        {
            if (a & 1 == 1) suma*=2;
            a>>=1;
        }
        cout << suma << "\n";
    }
}
