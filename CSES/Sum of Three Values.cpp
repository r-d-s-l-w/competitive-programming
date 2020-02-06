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
 
pi exist(int first, int sum){
    int it = n-1;
    for (int i=first+1; i<n; ++i){
        while(tab[it].F + tab[i].F >= sum && it > i) {
            if (tab[it].F + tab[i].F == sum)
                return {i, it};
            --it;
        }
    }
    return {-1, -1};
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    tab.resize(n);
    for (int i=0; i<n; ++i){
        cin >> tab[i].F;
        tab[i].S = i+1;
    } sort(ALL(tab));
 
    for (int i=0; i<n; ++i){
        pi tmp = exist(i, k - tab[i].F);
        if (tmp != pi{-1, -1}) {
            cout << tab[tmp.F].S << ' ' << tab[tmp.S].S << ' ' << tab[i].S;
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
 
}
