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
 
const int coupon = 100010;
vector<pi> adj[200100];
vector<ll> res(200100, 1e18);
vector<bool> vis(200100, 0);
int n, m;
 
void dijkstra(int s){
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, s});
    res[s] = 0;
 
    while (!pq.empty()){
        pll tmp = pq.top(); pq.pop();
        if (vis[tmp.S]) continue;
        vis[tmp.S] = true;
 
        for (auto u: adj[tmp.S]){
            if (res[u.F] > res[tmp.S] + u.S){
                res[u.F] = res[tmp.S] + u.S;
                pq.push({res[u.F], u.F});
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
        adj[a+coupon].PB({b+coupon, c});
        adj[a].PB({b+coupon, c/2});
    }
 
    dijkstra(1);
 
    cout << res[n+coupon] << endl;
 
}
