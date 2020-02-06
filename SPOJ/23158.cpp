#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, tab[100000];
    cin >> t;
    while (t--)
    {
        int x=0, maks=0;
        cin >> n;
        for (int i=0; i<n; i++)
        {
            cin >> tab[i];
            x+=tab[i];
            if (x>maks) maks=x;
            else if (x<0) x=0;
        }
        if (maks>0) cout << maks << "\n";

        else
        {
            int m=-1000000;
            for (int i=0; i<n; i++) if (tab[i]>m) m=tab[i];
            cout << m << "\n";
        }
    }
}
