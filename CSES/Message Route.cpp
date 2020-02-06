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
vi from(100100,-1);
vi res;
 
void bfs(int s){
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int tmp = q.front(); q.pop();
        for (auto u: adj[tmp]){
            if (!vis[u]){
                vis[u] = true;
                from[u] = tmp;
                q.push(u);
            }
        }
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
 
    bfs(1);
 
    if(vis[n] == false){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    while(n != -1){
        res.PB(n);
        n = from[n];
    }
    reverse(ALL(res));
    cout << res.size() << endl;
    for (auto u: res)
        cout << u << ' ';
    cout << endl;
}
