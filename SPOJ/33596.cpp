#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long long int n, x, q, a, arr[64], xd=1;
    for (int i=0; i<64; i++)
    {
        arr[i]=xd;
        xd*=2;
    }
    cin >> n;
    unsigned long long int tab[n];
    for (int i=0; i<n; i++) cin >> tab[i];
    cin >> q;
    while (q--)
    {
        int wynik=0;
        cin >> a;
        if (a>63) cout << 0 << endl;
        else
        {
            for (int i=0; i<n; i++)
            {
                if (tab[i]>=arr[a-1]&&tab[i]<arr[a]) wynik++;
            }
            cout << wynik << endl;
        }
    }
}
