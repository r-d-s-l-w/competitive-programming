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
 
string s;
int z;
vi adj[IN];
int x, c;
int dp[IN][2];
int dp2[IN][2];
 
void ini(){
    for (int i=0; i<=s.length()*2; ++i){
        adj[i].clear();
        for (int j=0; j<2; ++j){
            dp[i][j] = INF;
            dp2[i][j] = -INF;
        }
    }
    x = 0;
    c = -1;
}
 
void add_edge(int par){
    ++x;
    adj[par].PB(x);
    adj[x].PB(par);
}
 
void construct_tree(int parent){
    ++c;
    if (s[c] == '1'){
        add_edge(parent);
        construct_tree(x);
    }
    else if (s[c] == '2'){
        add_edge(parent);
        construct_tree(x);
        add_edge(parent);
        construct_tree(x);
    }
}
 
void dfs(int V, int pV){
    vi tmp;
    for (auto u: adj[V]){
        if (u == pV) continue;
        dfs(u, V); tmp.PB(u);
    }
    if (tmp.size() == 0){
        dp[V][0] = 0;
        dp[V][1] = 1;
    }
    else if (tmp.size() == 1){
        dp[V][0] = max(dp[tmp[0]][0],dp[tmp[0]][1]);
        dp[V][1] = dp[tmp[0]][0] + 1;
    }
    else if (tmp.size() == 2){
        dp[V][0] = max(dp[tmp[0]][1] + dp[tmp[1]][0],
                        dp[tmp[1]][1] + dp[tmp[0]][0]);
        dp[V][1] = dp[tmp[0]][0] + dp[tmp[1]][0] + 1;
    }
}
 
void dfs2(int V, int pV){
    vi tmp;
    for (auto u: adj[V]){
        if (u == pV) continue;
        dfs2(u, V); tmp.PB(u);
    }
    if (tmp.size() == 0){
        dp2[V][0] = 0;
        dp2[V][1] = 1;
    }
    else if (tmp.size() == 1){
        dp2[V][0] = min(dp2[tmp[0]][0],dp2[tmp[0]][1]);
        dp2[V][1] = dp2[tmp[0]][0] + 1;
    }
    else if (tmp.size() == 2){
        dp2[V][0] = min(dp2[tmp[0]][1] + dp2[tmp[1]][0],
                        dp2[tmp[1]][1] + dp2[tmp[0]][0]);
        dp2[V][1] = dp2[tmp[0]][0] + dp2[tmp[1]][0] + 1;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    cin >> z;
    while(z--){
        cin >> s; ini();
        construct_tree(0);
        dfs(0,0); dfs2(0,0);
        cout << max(dp[0][0],dp[0][1]) << ' ' << min(dp2[0][0],dp2[0][1]) << endl;
    }
}
