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
 
pi moves[4] = {{0,1},{0,-1},{1,0},{-1,0}};
vector<pi> adj[1010][1010];
char c;
bool vis[1010][1010];
int n, m;
 
void dfs(int a, int b){
    if (!vis[a][b]) return;
    vis[a][b] = 0;
    for (auto u: adj[a][b])
        dfs(u.F, u.S);
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
 
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            cin >> c;
            if (c == '.') vis[i][j] = 1;
        }
    }
 
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            if (vis[i][j]) {
                for (int k=0; k<4; ++k){
                    if (vis[i+moves[k].F][j+moves[k].S]){
                        adj[i+moves[k].F][j+moves[k].S].PB({i, j});
                        adj[i][j].PB({i+moves[k].F, j+moves[k].S});
                    }
                }
            }
        }
    }
 
    int res = 0;
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            if (!vis[i][j]) continue;
            dfs(i,j); ++res;
        }
    }
 
    cout << res << endl;
}
