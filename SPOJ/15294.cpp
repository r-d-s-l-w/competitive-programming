#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, x; string txt;
    vector <int> tab(2100000, 0);
    cin >> t;
    while (t--)
    {
        cin >> n >> txt;
        for (int i=n; i<2*n; i++) tab[i]=2*n-i;
        for (int i=n-1; i>0; i--) if (txt[n-i-1]=='A') tab[i]=tab[i*2+1]; else tab[i]=tab[i*2];
        cout << tab[1] << "\n";
    }
}
