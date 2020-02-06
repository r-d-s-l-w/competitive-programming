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
vector<int> parent(100100, -1);
vi res;
vi adj[100100];
int wynik;
 
void dfs(int s, int p){
    if (color[s] == 2 || wynik) return;
    parent[s] = p;
    if (color[s] == 1){
        wynik = s;
        int tmp = s;
        res.PB(s);
        do {
            tmp = parent[tmp];
            res.PB(tmp);
        } while(tmp != s);
        return;
    }
    color[s] = 1;
    for (auto u: adj[s]){
        if (u == p || wynik) continue;
        dfs(u, s);
    } color[s] = 2;
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
        if (color[i]) continue;
        dfs(i, -1);
    }
 
    if (!wynik){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    cout << res.size() << endl;
 
    for (auto u: res)
        cout << u << ' ';
    cout << endl;
}
