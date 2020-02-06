// Radoslaw Mysliwiec 2019
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
 
int n, m, a, b;
bool vis[200100];
bool color[200100];
pi edgel[200100];
vi adj[200100];
 
bool isBipartite(int v){
    for (auto u: adj[v]){
        if (!vis[u]){
            vis[u] = true;
            color[u] = !color[v];
            if (!isBipartite(u))
                return false;
        }
        else if (color[u] == color[v])
            return false;
    }
    return true;
}
 
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; ++i){
        cin >> a >> b;
        edgel[i] = {a,b};
        adj[a].PB(b);
        adj[b].PB(a);
    }
    if (isBipartite(1)){
        cout << "YES\n";
        for (int i=0; i<m; ++i){
            if (color[edgel[i].S]) cout << 1;
            else cout << 0;
        }
    }
    else cout << "NO\n";
 
    return 0;
}
