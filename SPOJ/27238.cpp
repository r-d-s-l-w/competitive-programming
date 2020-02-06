#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n; char tab[100][100];
    cin >> t;
    while (t--)
    {
        cin >> n;
        int maks=0, x=0;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin >> tab[i][j];
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (tab[i][j]=='.') x++;
                else {if (x>maks) maks=x; x=0;}
            }
            if (x>maks) maks=x;
            x=0;
            i+=maks;
        }
        cout << maks*maks << "\n";
    }
}
