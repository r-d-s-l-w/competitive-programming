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
 
int n;
vi dp(1000100, 1e9);
 
int solve(int x){
    if (dp[x] != 1e9) return dp[x];
 
    int tmp = x;
    int tmp2 = 1e9;
    while (tmp != 0){
        if (tmp%10 != 0) tmp2 = min(tmp2, solve(x - tmp%10) + 1);
        tmp /= 10;
    }
    return dp[x] = tmp2;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n;
 
    dp[0] = 0;
 
    cout << solve(n) << endl;
 
}
