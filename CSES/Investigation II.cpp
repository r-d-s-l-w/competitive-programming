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
 
constexpr ll MOD = 1e9 + 7;
 
vll dist(100100, 1e18);
vll ways(100100, 0);
vi shortest(100100, 1e9);
vi longest(100100, -1e9);
vector<bool> vis(100100, 0);
vector<pi> adj[100100];
vi topo;
int n, m;
 
void dijkstra(int s){
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, s});
    ways[s] = 1;
    shortest[s] = longest[s] = dist[s] = 0;
 
    while(!pq.empty()){
        pll tmp = pq.top(); pq.pop();
        if (vis[tmp.S]) continue;
        vis[tmp.S] = true;
 
        for (auto u: adj[tmp.S]){
            if (dist[u.F] > dist[tmp.S] + u.S){
                dist[u.F] = dist[tmp.S] + u.S;
                ways[u.F] = ways[tmp.S] % MOD;
                shortest[u.F] = shortest[tmp.S] + 1;
                longest[u.F] = longest[tmp.S] + 1;
                pq.push({dist[u.F], u.F});
            }
            else if (dist[u.F] == dist[tmp.S] + u.S){
                ways[u.F] += ways[tmp.S];
                shortest[u.F] = min(shortest[u.F], shortest[tmp.S] + 1);
                longest[u.F] = max(longest[u.F], longest[tmp.S] + 1);
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
        adj[a].PB({b, c});
    }
 
    dijkstra(1);
 
    cout << dist[n] << ' ' << ways[n] % MOD << ' ' << shortest[n] << ' ' << longest[n] << endl;
 
}
 
