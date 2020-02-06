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
#define debug if(1)
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;
using ordered_set = tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update>;
 
int n;
char s[1001000];
int dp[1001000][2]; // 0 = Vanilla
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n;
    cin >> s+1;
 
    for (int i=1; i<=n; ++i){
        if (s[i] == 'V'){
            dp[i][0] = min(dp[i-1][0] + 1, dp[i-1][1] + 2);
            dp[i][1] = min(dp[i-1][1] + 2, dp[i-1][0] + 3);
        }
        if (s[i] == 'C'){
            dp[i][0] = min(dp[i-1][0] + 4, dp[i-1][1] + 3);
            dp[i][1] = min(dp[i-1][1] + 2, dp[i-1][0] + 3);
        }
    }
 
    cout << min(dp[n][0], dp[n][1]) << endl;
}
