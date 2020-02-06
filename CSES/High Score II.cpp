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
 
vector<tuple<int, int, int>> edgel;
vector<ll> res(2550,-1e18);
vector<bool> vis(2550, 0);
vi adj[2550];
int n, m;
 
void bellman_ford(int s){
    res[s] = 0;
    for (int i=1; i<n; ++i)
    for (auto u: edgel)
        res[get<1>(u)] = max(res[get<1>(u)], res[get<0>(u)] + get<2>(u));
}
 
void dfs(int s){
    if (vis[s]) return;
    vis[s] = 1;
    for (auto u: adj[s])
        dfs(u);
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
    for (int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        tuple<int, int, int> tmp{a, b, c};
        edgel.PB(tmp);
        adj[a].PB(b);
    }
 
    bellman_ford(1);
 
    vi nodes_on_cycle;
    vi final_nodes;
 
    for (auto u: edgel){
        if (res[get<1>(u)] < res[get<0>(u)] + get<2>(u)){
            nodes_on_cycle.PB(get<1>(u));
        }
    }
 
    dfs(1);
    for (auto u: nodes_on_cycle){
        if (vis[u] == 1) final_nodes.PB(u);
    }
 
    vis.assign(2250,0);
 
    for (auto u: final_nodes)
        dfs(u);
 
    if (vis[n] == 1) cout << -1 << endl;
    else cout << res[n] << endl;
 
}
