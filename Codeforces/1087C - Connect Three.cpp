//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
 
using namespace std;
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;
 
 
 
int main(){
    ios_base::sync_with_stdio(0); //cin.tie(0);
    pii xd;
    vector <pair<int,int>> tab;
    int x[3], y[3], cp[3];
    cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
    cp[0] = x[0];
    cp[1] = x[1];
    cp[2] = x[2];
    sort(cp, cp+3);
    int bestx;
    for (int i=cp[0]; i<=cp[2]; ++i){
        if (cp[1]==i || cp[2]==i) {
            bestx = i;
            break;
        }
    }
    cp[0] = y[0];
    cp[1] = y[1];
    cp[2] = y[2];
    sort(cp, cp+3);
    for (int i=cp[0]; i<=cp[2]; ++i){
        tab.PB(MP(bestx,i));
    }
    for (int i=0; i<3; ++i){
        while (x[i] != bestx){
            tab.PB(MP(x[i],y[i]));
            if (x[i]<bestx) x[i]++;
            else x[i]--;
        }
    }
    cout << tab.size() << "\n";
    for (int i=0; i<tab.size(); ++i)
        cout << tab[i].F << ' ' << tab[i].S << "\n";
}
