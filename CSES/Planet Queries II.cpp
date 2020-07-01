/// Radoslaw Mysliwiec 2020
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
using matrix = vector<vi>;
using ordered_set = tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update>;

int n, a, b, q, maxTwoPower;
matrix indeks, krawedz, transponowany;
vi id, dist;
vector<bool> vis;

void input(){
    cin >> n >> q;
    maxTwoPower = 32 - __builtin_clz(n-1); // 2^(32 - __builtin_clz(n-1)) - pierwsza potega dwojki >= n
    id.resize(n+1, 0);
    transponowany.resize(n+1);
    vis.resize(n+1, 0);
    dist.resize(n+1, 1000000);
    indeks.resize(n+1);
    krawedz.resize(maxTwoPower+1, vi(n+1));

    for (int i=1; i<=n; ++i){
        cin >> b;
        krawedz[0][i] = b;
        transponowany[b].PB(i);
    }
}

void buildEdges(){
    for (int i=1; i<=maxTwoPower; ++i){
        for (int j=1; j<=n; ++j){
            krawedz[i][j] = krawedz[i-1][krawedz[i-1][j]];
        }
    }
}

void dfs(int v, int _id){
    int dist = 0;
    while(indeks[v].size() < 2 && (id[v] == 0 || id[v] == _id)){
        id[v] = _id;
        indeks[v].push_back(dist);
        ++dist;
        v = krawedz[0][v];
    }
}

void bfs(){
    queue<int> q;

    for (int i=1; i<=n; ++i){
        if (indeks[i].size() == 2){
            q.push(i);
            dist[i] = 0;
            vis[i] = true;
        }
    }

    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for (auto u: transponowany[tmp]){
            if (vis[u]) continue;
            q.push(u);
            dist[u] = dist[tmp] + 1;
            vis[u] = true;
        }
    }
}

int go(int v, int k){
    for (int i=maxTwoPower; i>=0; --i){
        if ((1<<i) <= k){
            k -= (1<<i);
            v = krawedz[i][v];
        }
    }
    return v;
}

int query(int start, int dest){
    if (start == dest) return 0;
    if (dist[start] <= dist[dest] && dist[dest] != 0) return -1;

    if (indeks[dest].size() != 2){
        if (go(start, dist[start] - dist[dest]) == dest) return dist[start] - dist[dest];
        else return -1;
    }

    int res = 0;

    if (id[krawedz[maxTwoPower][start]] != id[krawedz[maxTwoPower][dest]]) return -1;
    res += dist[start];
    start = go(start, res);
    if (indeks[start][0] <= indeks[dest][0]) return res + indeks[dest][0] - indeks[start][0];
    return res + indeks[dest][1] - indeks[start][0];
}

void debug(){
    cout << n << endl;
    for (int i=1; i<=n; ++i){
        cout << id[i] << ":    ";
        for (auto u: indeks[i])
            cout << u << ' ';
        cout << endl;
    }
    for (int i=1; i<=n; ++i)
        cout << dist[i] << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input();
    buildEdges();

    for (int i=1; i<=n; ++i)
        dfs(i, i);

    bfs();

    //debug();

    while (q--){
        cin >> a >> b;
        cout << query(a, b) << endl;
    }
}
