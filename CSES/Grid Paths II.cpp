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
 
constexpr ll MOD = 1e9 + 7;
 
int n;
vector<vll> paths(1010, vll(1010, 0));
vector<vector<char>> tab(1010, vector<char>(1010));
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n;
 
    for (int i=1; i<=n; ++i)
    for (int j=1; j<=n; ++j)
        cin >> tab[i][j];
 
    paths[0][1] = 1;
 
    for (int i=1; i<=n; ++i)
    for (int j=1; j<=n; ++j)
        if (tab[i][j] != '*')
            paths[i][j] = (paths[i-1][j] + paths[i][j-1]) % MOD;
 
    cout << paths[n][n] << endl;
 
}
