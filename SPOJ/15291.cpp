#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n;
    cin >> t;
    while(t--)
        {
        cin >> n;
        if(n==1) cout << 8 << "\n";
        else if(n == 2) cout << 33 << "\n";
        else
        {
            int wynik=0;
            int x=n/2;
            wynik+=4*n*n+3*n+1;
            n%2==0 ? wynik += (2*n*n+n) : wynik += (2*((x+1)*(2*n+1)-n));
            wynik += 4*(n-x)*x;
            cout << wynik << "\n";
        }
    }
}
