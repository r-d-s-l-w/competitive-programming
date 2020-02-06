#include <bits/stdc++.h>
#pragma GCC optimize("O3")
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
 
vector<pll> adj[1010];
ll dist[1010], vis[1010];
ll n;
 
void ini(){
    for (int i=0; i<1010; ++i){
        adj[i].clear();
    }
}
 
ll dijkstra(ll s, ll destination){
    for (int i=1; i<=n; ++i) {
        dist[i] = 1e15;
        vis[i] = 0;
    }
    dist[s] = 0;
    queue<pll> pq;
    pq.push(MP(0,s));
    while (!pq.empty()){
        ll A = pq.front().S; pq.pop();
        if (vis[A]) continue;
        vis[A] = true;
        for (auto u : adj[A]){
            ll B = u.F, W = u.S;
            if (dist[A] + W < dist[B]){
                dist[B] = dist[A] + W;
                pq.push(MP(-dist[B],B));
            }
        }
        if (A == destination) return dist[A];
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll T, m, q, x, y, z, a, b;
    cin >> T;
    while (T--){
        ini();
        cin >> n >> m;
        for (int i=1; i<n; ++i){
            cin >> x >> y >> z;
            adj[x].PB(MP(y,z));
            adj[y].PB(MP(x,z));
        }
        int swit;
        while (m--){
            cin >> swit;
            if (swit == 1){
                cin >> x >> y >> z;
                for (int i=0; i<adj[x].size(); ++i)
                    if (adj[x][i].F == y) adj[x][i].S = z;
                for (int i=0; i<adj[y].size(); ++i)
                    if (adj[y][i].F == x) adj[y][i].S = z;
            }
            else {
                cin >> a >> b;
                cout << dijkstra(a,b) << endl;
            }
        }
    }
    return 0;
}
