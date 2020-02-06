#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, k, n, a; long long x, y, maks;
    cin >> t;
    while (t--)
    {
        x=0; y=0; maks=0;
        cin >> k >> n;
        vector <int> tab(k,0);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<k; j++)
            {
                cin >> a;
                if (a!=tab[j]) {y++; if (tab[j]-a>0) x+=tab[j]-a; else x+=a-tab[j]; tab[j]=a;}
            }
            if (x>maks) maks=x; x=0;
        }
        for (int j=0; j<k; j++)
            {
                if (tab[j]!=0) {y++; if (tab[j]>0) x+=tab[j]; else x+=tab[j]; tab[j]=0;}
            }
            if (x>maks) maks=x; x=0;
        cout << maks << " " << y << endl;
    }
}
