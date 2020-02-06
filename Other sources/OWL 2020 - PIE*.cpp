/// Radoslaw Mysliwiec 2020
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
#define debug if(1)
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
 
constexpr ll MOD = 1e9 + 7;
 
vll tab(1000001);
 
void precompute(){
    ll a = 2;
    ll maxb = 1e12;
    tab[0] = 0;
    tab[1] = 1;
    for (; a*a <= maxb; ++a)
        tab[a] = a*a;
    tab.PB(ll(1e18));
}
 
void solve(){
    ll a, b, sum = 0;
    cin >> a >> b;
    ll it = 2;
    while(b >= tab[it-1]){
        if (tab[it] - 1 >= a){
            sum += (it-1) * ( min(tab[it]-1, b) - max(tab[it-1], a) + 1);
            sum %= MOD;
        } ++it;
    }
    cout << sum << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    precompute();
    int z;
    cin >> z;
    while(z--){
        solve();
    }
}
