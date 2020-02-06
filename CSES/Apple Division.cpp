/// Radoslaw Mysliwiec 2020
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;
 
int n;
ll w1, w2, W;
ll tab[30], res = 1e18;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n;
    for (int i=1; i<=n; ++i){
        cin >> tab[i];
        W += tab[i];
    }
 
    for (int i=0; i<(1<<n); ++i){
        w1 = 0;
        w2 = 0;
        for (int j=0; j<n; ++j){
            if (i & (1<<j)) w1 += tab[j+1];
            else w2 += tab[j+1];
        }
        res = min(res, abs(w1 - w2));
    }
 
    cout << res << endl;
 
 
}
