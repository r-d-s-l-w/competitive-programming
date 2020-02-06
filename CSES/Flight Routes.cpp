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
 
vector<pi> adj[100100];
vector<char> vis(100100, 0);
vector<ll> res[100100];
int n, m, k;
 
void dijkstra(int s){
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,s});
 
    while(!pq.empty()){
        pll tmp = pq.top(); pq.pop();
        if (vis[tmp.S] >= k) continue;
        res[tmp.S].PB(tmp.F);
        for (auto u: adj[tmp.S])
            pq.push({u.S + tmp.F, u.F});
        ++vis[tmp.S];
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> m >> k;
 
    for (int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].PB({b,c});
    }
 
    dijkstra(1);
 
 
    for (auto u: res[n])
        cout << u << ' ';
    cout << endl;
 
 
}
