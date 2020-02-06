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
using matrix = vector<vll>;
 
constexpr ll MOD = 1e9 + 7;
 
int n, m;
vi adj[100100];
vi adjT[100100];
vi topo;
vll res(100100, 0);
vector<bool> vis(100100, 0);
 
void dfs(int s){
    if (vis[s]) return;
    vis[s] = true;
    for (auto u: adj[s])
        dfs(u);
    topo.PB(s);
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].PB(b);
        adjT[b].PB(a);
    }
 
    for (int i=1; i<=n; ++i)
        dfs(i);
    reverse(ALL(topo));
 
    res[1] = 1;
 
    for (int i=0; i<n; ++i){
        ll tmp = 0;
        for (auto u: adjT[topo[i]])
            tmp += res[u];
        if (topo[i] != 1) res[topo[i]] = tmp % MOD;
    }
 
    cout << res[n] << endl;
 
 
}
