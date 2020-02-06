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
 
vector<int> adj[100100];
vector<int> dfst[100100];
vector<int> parent(100100, 0);
vector<char> color(100100, 0);
int n, m, k;
pi cycle;
 
void dfs(int s){
    color[s] = 1;
    for (auto u: adj[s]){
        if (color[u] == 1 && u != s) cycle = {s, u};
        if (color[u] > 0) continue;
        parent[u] = s;
        dfs(u);
    }
    color[s] = 2;
}
 
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
 
    for (int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].PB(b);
    }
 
    for(int i=1; i<=n; ++i){
        if (!color[i]) dfs(i);
    }
 
    if (cycle.F != 0){
        vi res = {cycle.S, cycle.F};
        do{
            cycle.F = parent[cycle.F];
            res.PB(cycle.F);
        } while(cycle.F != cycle.S);
        reverse(ALL(res));
        cout << res.size() << endl;
        for (auto u: res)
            cout << u << ' ';
        cout << endl;
    }
    else cout << "IMPOSSIBLE\n";
}
