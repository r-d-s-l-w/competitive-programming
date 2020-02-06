#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector <int> tab;
    int d, k, n, xd, maks; string x;
    cin >> d;
    while (d--)
    {
        cin >> n >> k >> x;
        tab.push_back(0); xd=maks=0;
        for (int i=0; i<x.length(); i++)
            if (x[i]=='1') {tab.push_back(i+1); xd++;} tab.push_back(x.length()+1);
        if (xd<=k) cout << n << endl;
        else {
        for (int i=0; i<=xd-k; i++)
            if (tab[i+k+1]-tab[i]>maks) maks=tab[i+k+1]-tab[i];
        cout << maks-1 << endl;}
        tab.clear();
    }
    return 0;
}
