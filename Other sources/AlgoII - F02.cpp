/// Radoslaw Mysliwiec 2019
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
 
constexpr int INI = -1;
constexpr int INF = 1e9 + 1;
constexpr int IN = 1e6 + 10;
constexpr int MOD = 1e9 + 7;
constexpr ld EPS = 1e-9;
 
int dp[4010][4010], n, z,tmp;
int tab[4010];
 
int solve(int L, int R){
    if (dp[L][R] != -INF) return dp[L][R];
    if (L == R) return dp[L][R] = tab[L];
    return dp[L][R] = max(tab[R]-solve(L,R-1),tab[L]-solve(L+1,R));
}
 
void ini(int x){
    for (int i=0; i<=x; ++i)
    for (int j=0; j<=x; ++j)
        dp[i][j] = -INF;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    cin >> z;
    while(z--){
        cin >> n;
        ini(2*n);
        int sum = 0;
        for (int i=0; i<n; ++i){
            cin >> tab[i];
            tab[n+i] = tab[i];
            sum += tab[i];
        }
        int res = -INF;
        for (int i=0;i<n;++i)
            res = max(res,solve(i,n+i-1));
        //cout << res << endl;
 
        cout << (sum+res)/2 << ' ' << (sum-res)/2 << endl;
    }
}
