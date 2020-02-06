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
constexpr ll two = 500000004;
constexpr ll six = 166666668;
 
void solve(){
    ll a, b, res, L, R;
 
    cin >> a >> b;
 
    ll tmpL = 0, tmpR = 1e9;
 
    while(tmpL < tmpR){
        ll mid = (tmpL+tmpR)/2;
        if (mid * mid >= a) tmpR = mid;
        else tmpL = mid + 1;
    } L = tmpL;
 
    tmpL = 0, tmpR = 1e9;
 
    while(tmpL < tmpR){
        ll mid = (tmpL+tmpR)/2 + 1;
        if (mid * mid - 1 <= b) tmpL = mid;
        else tmpR = mid - 1;
    } R = tmpL - 1;
 
    // cout << L << ' ' << R << endl;
 
    ll expr1, expr2, expr3, expr4, expr5;
    expr1 = R*(R+1);
    expr1 %= MOD;
    expr1 *= 2*R + 1;
    expr1 %= MOD;
    expr1 *= 2*six;
    expr1 %= MOD;
    expr2 = (L-1)*L;
    expr2 %= MOD;
    expr2 *= 2*L - 1;
    expr2 %= MOD;
    expr2 *= 2*six;
    expr2 %= MOD;
    expr3 = (R*(R+1))/2 - (L*(L-1))/2;
    expr3 %= MOD;
    expr4 = (b - ((R+1)*(R+1)) + 1);
    expr4 %= MOD;
    expr4 *= R+1;
    expr4 %= MOD;
    expr5 = L*L - a;
    expr5 %= MOD;
    expr5 *= L-1;
    expr5 %= MOD;
    res = expr1 - expr2 + expr3 + expr4 + expr5;
    res %= MOD;
    if (res < 0) res += MOD;
    cout << res << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int z;
    cin >> z;
    while(z--){
        solve();
    }
}
