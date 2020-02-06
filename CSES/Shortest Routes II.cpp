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
 
int n, m, q;
vector<vector<ll>> dp(510,vector<ll>(510, 1e18));
 
void floyd_warschall(){
    for (int i=1; i<=n; ++i)
        dp[i][i] = min(ll(0), dp[i][i]);
 
    for (int k=1; k<=n; ++k)
    for (int i=1; i<=n; ++i)
    for (int j=1; j<=n; ++j)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> m >> q;
    for (int i=0; i<m; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[a][b], c);
    }
 
    floyd_warschall();
 
    while (q--){
        int a, b;
        cin >> a >> b;
        if (dp[a][b] == 1e18) cout << -1 << endl;
        else cout << dp[a][b] << endl;
    }
}
