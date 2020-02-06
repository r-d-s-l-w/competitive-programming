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
 
vector<bool> vis(100100, 0);
vector<int> adj[100100];
vector<int> adjT[100100];
vector<int> topo;
vector<int> res(100100, 0);
vector<int> parent(100100, 0);
vector<bool> jest_jeden(100100, 0);
int n, m;
 
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
 
    for (int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].PB(b);
        adjT[b].PB(a);
    }
    for (int i=1; i<=n; ++i)
        dfs(i);
    reverse(ALL(topo));
 
    jest_jeden[1] = 1;
 
    //for (auto u: topo)
        //cout << u << ' '; cout << endl;
 
    for (int i=0; i<n; ++i){
        for (auto u: adjT[topo[i]]){
            if (res[u] + 1 > res[topo[i]] && jest_jeden[u]){
                res[topo[i]] = res[u] + 1;
                parent[topo[i]] = u;
                jest_jeden[topo[i]] = 1;
            }
        }
    }
 
    if (res[n] == 0){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vi tmp; int tmp2 = n;
    cout << res[n] + 1 << endl;
    for (int i=0; i<=res[n]; ++i){
        tmp.PB(tmp2);
        tmp2 = parent[tmp2];
    } reverse(ALL(tmp));
    for (auto u: tmp)
        cout << u << ' ';
    cout << endl;
}
