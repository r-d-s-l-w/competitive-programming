/// Radoslaw Mysliwiec 2019
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
 
using namespace std;
 
#define F first
#define S second
#define PB emplace_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
#define DEBUG(x) cout << '>' << #x << ": " << x << endl;
#define REP(i,n) for (int i = 1; i <= n; ++i)
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;
 
constexpr ll MOD = 1000000007;
constexpr ll INI = -1;
constexpr ll IN = 350 + 10;
constexpr ll INF = 1e9 + 1;
constexpr ld EPS = 1e-9;
 
int tab[300300], res;
vector<pi> bucket;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> tab[i];
    int i=1, j=n;
    if (tab[i] != tab[j])
        cout << n - 1 << endl;
    else {
        for (;i<n; ++i){
            if (tab[i] != tab[j]) break;
        }
        res = max(res, j - i);
        i=1; j=n;
        for (;j>1; --j){
            if (tab[i] != tab[j]) break;
        }
        res = max(res,j - i);
        cout << res << endl;
    }

    return 0;
}
