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
 
int n, x;
vll coins(110);
vll dp(1000100, 0);
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> x;
 
    dp[0] = 1;
 
    for (int i=1; i<=n; ++i)
        cin >> coins[i];
 
    for (int j=0; j<=x; ++j)
        for (int i=1; i<=n; ++i)
            if (j >= coins[i]) {
                dp[j] += dp[j - coins[i]];
                dp[j] %= ll(1e9 + 7);
            }
 
    cout << dp[x] << endl;
 
}
