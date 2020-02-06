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
 
int t;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> t;
 
    while (t--){
        ll x, y, res;
        cin >> x >> y;
        if (x >= y){
            res = x*x - x + 1;
            if (x % 2) res -= (x - y);
            else res += (x - y);
        }
        else {
            res = y*y - y + 1;
            if (y % 2) res += (y - x);
            else res -= (y - x);
        }
        cout << res << endl;
    }
 
 
}
