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
 
vector<bool> vis(100100, 0);
vector<pll> adj[100100];
vector<ll> res(100100, 1e18);
int n, m;
 
void dijkstra(int s){
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    res[s] = 0;
    pq.push({0,s});
 
    while(!pq.empty()){
        pll tmp = pq.top(); pq.pop();
        if(vis[tmp.S]) continue;
        vis[tmp.S] = true;
        for (auto u: adj[tmp.S]){
            if (res[u.F] > res[tmp.S] + u.S){
                res[u.F] = res[tmp.S] + u.S;
                pq.push({res[u.F],u.F});
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
    for (int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].PB({b,c});
    }
 
    dijkstra(1);
 
    for (int i=1; i<=n; ++i)
        cout << res[i] << ' ';
    cout << endl;
}
