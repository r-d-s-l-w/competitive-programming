#include <bits/stdc++.h>
 
using namespace std;
 
long long a, b;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector <int> tab;
    int n; char x; int gold = 0, silver = 0, suma=0;
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> x;
        if (x=='G'){
            gold++;
            suma++;
            if (silver) tab.push_back(-silver);
            silver = 0;
        }
        else {
            silver++;
            if (gold) tab.push_back(gold);
            gold = 0;
        }
    }
    if (silver) tab.push_back(-silver);
    if (gold) tab.push_back(gold);
    int maks = 0;
    for (int i=0; i<tab.size(); ++i){
        if (tab[i]>0){
            if (suma>tab[i]){
                maks = max(maks, tab[i]+1);
            }
            else maks = max(maks, tab[i]);
        }
        else if (tab[i]==-1){
            if (i > 0 && i < tab.size()-1){
                if (tab[i-1]+tab[i+1]<suma){
                    maks = max(maks, tab[i+1] + tab[i-1] + 1);
                }
                else maks = max(maks, tab[i+1] + tab[i-1]);
            }
        }
    }
    cout << maks;
}
