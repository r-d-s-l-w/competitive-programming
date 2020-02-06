// Radoslaw Mysliwiec 2019
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB emplace_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;
 
ll gcd(ll a, ll b){
    return !b?a:gcd(b,a%b);
}
 
ll n, m, q, TMP, TMP2, GCD;
 
ll ktora_cwiartka(ll a, ll b){
    if (a == 1)
        return (b-1)/TMP;
 
    return (b-1)/TMP2;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a, b, c, d;
    cin >> n >> m >> q;
    GCD = gcd(n,m);
    TMP = n/GCD;
    TMP2 = m/GCD;
    while (q--){
        cin >> a >> b >> c >> d;
        if (ktora_cwiartka(a,b) == ktora_cwiartka(c,d))
            cout << "YES\n"; else cout << "NO\n";
        //cout << ktora_cwiartka(a,b) << ' ' << ktora_cwiartka(c,d) << endl;
    }
 
 
    return 0;
}
