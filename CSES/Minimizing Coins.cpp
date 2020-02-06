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
vi tab;
vi dp(1000100, 1e9);
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> x;
 
    tab.resize(n+1);
 
    for (int i=1; i<=n; ++i)
        cin >> tab[i];
 
    dp[0] = 0;
 
    for (int i=1; i<=n; ++i)
        for (int j=tab[i]; j<=x; ++j)
            dp[j] = min(dp[j], dp[j - tab[i]] + 1);
 
    if (dp[x] == 1e9) cout << -1 << endl;
    else cout << dp[x] << endl;
}
