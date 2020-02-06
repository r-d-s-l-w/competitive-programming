#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n; short int tab[1000000];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=0; i<n; i++) cin >> tab[i];
        int maks=0, x=2;
        if (n>2)
        {
            for (int i=1; i<n-1; ++i)
            {
                tab[i]>tab[i-1]&&tab[i]>tab[i+1]||tab[i]<tab[i-1]&&tab[i]<tab[i+1]?x++:x=2;
                x-2>maks?maks=x-2:maks=maks;
            }
            maks==0?cout<<0<<"\n":cout<<maks+2<<"\n";
        }
        else cout << 0 << "\n";
    }
}
