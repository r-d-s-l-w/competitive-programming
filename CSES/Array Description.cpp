/// Radoslaw Mysliwiec 2020
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
using ordered_set = tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr ll MOD =  1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;

    cin >> n >> m;

    vector<vll> dp(n+1, vll(m+2, 0));
    vi tab(n+1);

    for (int i=1; i<=n; ++i)
        cin >> tab[i];

    if (tab[1] == 0){
        for (int i=1; i<=m; ++i)
            dp[1][i] = 1;
    }
    else dp[1][tab[1]] = 1;

    for (int i=2; i<=n; ++i){
        if (tab[i] == 0){
            for (int j=1; j<=m; ++j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j+1] + dp[i-1][j-1];
                while (dp[i][j] >= MOD) dp[i][j] -= MOD;
            }
        }
        else {
            dp[i][tab[i]] = dp[i-1][tab[i]] + dp[i-1][tab[i]+1] + dp[i-1][tab[i]-1];
            while (dp[i][tab[i]] >= MOD) dp[i][tab[i]] -= MOD;
        }
    }

    ll res = 0;

    for (int i=1; i<=m; ++i)
        res += dp[n][i];

    cout << res % MOD << endl;

}
