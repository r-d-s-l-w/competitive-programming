//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
 
using namespace __gnu_pbds;
using namespace std;
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;
 
int main(){
    ios_base::sync_with_stdio(0); //cin.tie(0);
    int n, k;
    vector<pii> tab;
    cin >> n >> k;
    for (int i=1; i<k; ++i){
        if (n%i == 0) tab.push_back(MP(n/i,i));
    }
    sort(tab.begin(), tab.end());
    //for (int i=0; i<tab.size(); ++i) cout << tab[i].F << ' ' << tab[i].S << "\n";
    cout << tab[0].F * k + tab[0].S;
}
