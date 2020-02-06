#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, tab[100][100], arr[100][100], x; bool xd;
    cin >> t;
    while (t--)
    {
        cin >> n; xd=true;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin >> arr[i][j];
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin >> tab[i][j];
        for(int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                x=0;
                for (int l=0; l<j; l++) if (arr[i][l]==1&&arr[l][j]==1) x++;
                for (int l=j+1; l<n; l++) if (arr[i][l]==1&&arr[l][j]==1) x++;
                if (x!=tab[i][j]) xd=false;
            }
            if (xd==false) {cout << "NIE\n"; break;}
        }
        if (xd==true) cout << "TAK\n";
    }
}
