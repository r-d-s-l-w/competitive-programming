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
bool is_bipartite = 1;
vector<int> color(100100, 0);
vi adj[100100];
 
void dfs(int s, int c){
    if (color[s] != 0) return;
    color[s] = c;
    for (auto u: adj[s]){
        if (color[u] == color[s])
            is_bipartite = 0;
        c==1 ? dfs(u, 2) : dfs(u, 1);
    }
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
        if (color[i] != 0) continue;
        dfs(i, 1);
        if (!is_bipartite){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    for (int i=1; i<=n; ++i)
        cout << color[i] << ' ';
    cout << endl;
 
}
