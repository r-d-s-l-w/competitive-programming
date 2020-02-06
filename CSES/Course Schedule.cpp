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
 
vector<char> color(100100, 0);
vector<int> adj[100100];
vector<int> res;
bool cycle;
int n, m;
 
void dfs(int s){
    if (color[s] > 0) return;
    color[s] = 1;
    for (auto u: adj[s]){
        if (color[u] == 1) cycle = true;
        dfs(u);
    }
    color[s] = 2;
    res.PB(s);
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
 
    for (int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].PB(b);
    }
 
    for (int i=1; i<=n; ++i){
        dfs(i);
    }
 
    if (cycle) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    reverse(ALL(res));
    for (auto u: res)
        cout << u << ' ';
    cout << endl;
}
 
