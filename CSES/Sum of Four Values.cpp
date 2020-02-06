/// Radoslaw Mysliwiec 2020
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
#define dd cout << " debug";
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;
 
int n;
int k;
vector<pi> tab;
map<int,vector<pi>> mp;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    tab.resize(n);
    for (int i=0; i<n; ++i){
        cin >> tab[i].F;
        tab[i].S = i+1;
    } sort(ALL(tab));
 
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j)
            mp[tab[i].F + tab[j].F].PB({i, j});
 
    for (int i=0; i<n; ++i){
        for (int j=i+1; j<n; ++j){
            for (auto u: mp[k - tab[i].F - tab[j].F]){
                if (u.F != i && u.F != j && u.S != i && u.S != j){
                    cout << tab[i].S << ' ' << tab[j].S << ' ' << tab[u.F].S << ' ' << tab[u.S].S << endl;
                    return 0;
                }
            }
        }
    }
 
    cout << "IMPOSSIBLE\n";
 
} 
