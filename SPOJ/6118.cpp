#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long long int t, n, wynik;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n==1) cout << 1 << "\n";
        else{
        wynik=0;
        for (int i=1; i<sqrt(n); i++)
        {
            if (n%i==0) wynik+=i+n/i;
        }
        cout << wynik << endl;}
    }
}
