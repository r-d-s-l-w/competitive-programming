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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;

    cin >> n >> x;

    vi price(n+1), pages(n+1);

    for (int i=1; i<=n; ++i)
        cin >> price[i];

    for (int i=1; i<=n; ++i)
        cin >> pages[i];

    vi dp(x+1, 0);


    for (int i=1; i<=n; ++i){
        for (int w=x-price[i]; w>=0; --w){
            dp[w + price[i]] = max(dp[w + price[i]], dp[w] + pages[i]);
        }
    }

    cout << dp[x] << endl;
}
