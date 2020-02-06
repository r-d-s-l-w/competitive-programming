// Radoslaw Mysliwiec 2019
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
 
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
using pll = pair<ll,ll>;
using matrix = vector<vll>;
 
constexpr int INF = 1e9 + 1;
 
ll product(ll x) {
    ll prod = 1;
    while (x) {
        prod *= (x % 10);
        x /= 10;
    }
    return prod;
}
 
 
ll findNumber(ll l, ll r) {
    string a = to_string(l);
    string b = to_string(r);
 
    ll ans = r;
    for (ll i = 0; i < b.size(); i++) {
        if (b[i] == '0')
            continue;
 
        string curr = b;
        curr[i] = ((curr[i] - '0') - 1) + '0';
        for (ll j = i + 1; j < curr.size(); j++)
            curr[j] = '9';
        ll num = 0;
        for (auto c : curr)
            num = num * 10 + (c - '0');
        if (num >= l && product(ans) < product(num))
            ans = num;
    }
 
    return ans;
}
 
ll n, res = 1, temp = 999999999;
ll tab[9] = {100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    res = findNumber(1,n);
    cout << product(res) << endl;
    return 0;
}
