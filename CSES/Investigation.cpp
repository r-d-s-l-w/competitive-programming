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
vector<bool> vis2(100100, 0);
vector<bool> vis3(100100, 0);
vector<pi> adj[100100];
vector<pi> adjT[100100];
vector<pi> adjSP[100100];
vector<pi> adjSPT[100100];
vi topo;
int n, m;
 
void dijkstra(int s){
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, s});
    dist[s] = 0;
 
    while(!pq.empty()){
        pll tmp = pq.top(); pq.pop();
        if (vis[tmp.S]) continue;
        vis[tmp.S] = true;
 
        for (auto u: adj[tmp.S]){
            if (dist[u.F] > dist[tmp.S] + u.S){
                dist[u.F] = dist[tmp.S] + u.S;
                pq.push({dist[u.F], u.F});
            }
        }
    }
}
 
void dfs(int s){
    if (vis2[s]) return;
    vis2[s] = true;
    for (auto u: adjT[s]){
        if (dist[s] == dist[u.F] + u.S){
            adjSP[u.F].PB({s, u.S});
            adjSPT[s].PB({u.F, u.S});
            // cout << u.F << ' ' << s << ' ' << u.S << endl;
        }
        dfs(u.F);
    }
}
 
void dfs2(int s){
    if (vis3[s]) return;
    vis3[s] = true;
    for (auto u: adjSP[s])
        dfs2(u.F);
    topo.PB(s);
}
 
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
 
    for (int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].PB({b, c});
        adjT[b].PB({a, c});
    }
 
    dijkstra(1);
 
    //for (int i=1; i<=n; ++i){
    //    cout << dist[i] << ' ';
    //}
 
    dfs(n);
 
    // w grafie adjSP na pewno nie ma cykli
 
    dfs2(1);
    reverse(ALL(topo));
    ways[1] = 1;
    shortest[1] = 0;
    longest[1] = 0;
 
    for (int i=0; i<n; ++i){
        ll tmp = 0;
        for (auto u: adjSPT[topo[i]]){
            tmp += ways[u.F];
            shortest[topo[i]] = min(shortest[topo[i]], shortest[u.F] + 1);
            longest[topo[i]] = max(longest[topo[i]], longest[u.F] + 1);
        }
        if (topo[i] != 1) ways[topo[i]] = tmp % MOD;
    }
 
    cout << dist[n] << ' ' << ways[n] << ' ' << shortest[n] << ' ' << longest[n] << endl;
 
}
