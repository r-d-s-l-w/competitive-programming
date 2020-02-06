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
 
ll n, k;
vll a(200100);
 
ll check(ll x){
    ll tmp = 0;
    for (int i=0; i<n; ++i)
        tmp += x/a[i];
    return tmp;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> k;
 
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
 
    ll L = 0, R = 1e18/n;
    while (L < R){
        ll mid = (L + R)/2;
        if (check(mid) >= k) R = mid;
        else L = mid + 1;
    }
    cout << L << endl;
}
