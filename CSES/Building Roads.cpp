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
 
int n, m;
vector<bool> vis(100100, 0);
vi adj[100100];
vi res;
 
void dfs(int s){
    if (vis[s]) return;
    vis[s] = true;
    for (auto u: adj[s])
        dfs(u);
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
 
    for (int i=1; i<=n; ++i){
        if (vis[i]) continue;
        dfs(i);
        res.PB(i);
    }
 
    cout << res.size() - 1 << endl;
    for (int i=1; i<res.size(); ++i){
        cout << res[i] << ' ' << res[i-1] << endl;
    }
 
 
}
