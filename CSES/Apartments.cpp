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
 
int n, m, k, res;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> m >> k;
    vi a(n), b(m);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    for (int i=0; i<m; ++i){
        cin >> b[i];
    }
    sort(ALL(a)); sort(ALL(b));
    b.PB(2e9 + 3);
    int it = 0;
    for (int i=0; i<n; ++i){
        while (b[it] + k < a[i])
            ++it;
        if (abs(b[it] - a[i]) <= k){
            ++res; ++it;
        }
    }
    cout << res << endl;
