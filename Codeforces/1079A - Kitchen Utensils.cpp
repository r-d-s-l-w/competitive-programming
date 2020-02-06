#include <bits/stdc++.h>
 
using namespace std;
 
int tab[1000], xd;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, x, maks = 0;
    cin >> n >> k;
    for (int i=0; i<n; ++i){
        cin >> x;
        tab[x]++;
        if (tab[x] == 1) xd++;
        if (tab[x] > maks)
            maks = tab[x];
    }
        int sets = (maks + k - 1) / k;
        int lol = xd * sets * k;
        //cout << xd << " " << sets << endl;
        cout << lol - n;
}
