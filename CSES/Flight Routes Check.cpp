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
using ordered_set = tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update>;\

vector<vi> g, gT;
vi order, SSS;
vector<bool> vis;
int n, m;

void dfs1(int v){
    if (vis[v]) return;
    vis[v] = true;
    for (auto u: g[v])
        dfs1(u);
    order.PB(v);
}

void dfs2(int v, int V){
    if (vis[v]) return;
    vis[v] = true;
    SSS[v] = V;
    for (auto u: gT[v])
        dfs2(u, V);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    g.resize(n+1);
    gT.resize(n+1);
    SSS.resize(n+1);
    vis.resize(n+1, 0);

    for (int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].PB(b);
        gT[b].PB(a);
    }
    for (int i=1; i<=n; ++i){
        dfs1(i);
    } vis.assign(n+1, 0);
    reverse(ALL(order));

    int newV = 0;

    for (int i=0; i<n; ++i){
        if (vis[order[i]]) continue;
        ++newV;
        dfs2(order[i], newV);
    }

    if (newV == 1) {
        cout << "YES\n";
        return 0;
    }

    for (int i=1; i<=n; ++i){
        for (auto u: g[i]){
            if (SSS[i] != SSS[u]){
                cout << "NO\n";
                cout << u << ' ' << i << endl;
                return 0;
            }
        }
    }
}
