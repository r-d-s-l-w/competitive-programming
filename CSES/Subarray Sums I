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
 
ll n, x, res;
map<ll, int> mp;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> x;
 
    mp[0] = 1;
    ll tmp = 0;
    for (int i=0; i<n; ++i){
        int a; cin >> a;
        tmp += a;
        res += mp[tmp - x];
        ++mp[tmp];
    }
    cout << res << endl;
}
