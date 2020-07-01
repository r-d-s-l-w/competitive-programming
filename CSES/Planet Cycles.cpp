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

int n, a, on_cycle;
vi nextt, parent, cycle_size, color;
vector<pi> to_cycle;

void dfs(int v){
    if (color[v]) return;
    color[v] = 1;
    if (color[nextt[v]] == 1)
        on_cycle = v;
    dfs(nextt[v]);
    color[v] = 2;
}

void dfs2(int v){
    if (color[v]) return;
    color[v] = 1;
    dfs2(nextt[v]);
    to_cycle[v].F = to_cycle[nextt[v]].F + 1;
    to_cycle[v].S = to_cycle[nextt[v]].S;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    nextt.resize(n+1, 0);
    color.resize(n+1, 0);
    parent.resize(n+1, -1);
    cycle_size.resize(n+1, 0);
    to_cycle.resize(n+1);

    for (int i=1; i<=n; ++i){
        cin >> a;
        nextt[i] = a;
        to_cycle[i] = {0, i};
    }

    int tmp = -1;

    for (int i=1; i<=n; ++i){
        dfs(i);
        if (on_cycle != tmp){
            tmp = on_cycle;
            vi cycle;
            do {
                cycle.PB(tmp);
                tmp = nextt[tmp];
            } while (on_cycle != tmp);

            for (auto u: cycle){
                cycle_size[u] = cycle.size();
            }
        }
    }

    for (int i=1; i<=n; ++i){
        if (!cycle_size[i]) {
            color[i] = 0;
        }
    }

    for (int i=1; i<=n; ++i){
        dfs2(i);
    }

    for (int i=1; i<=n; ++i){
        cout << to_cycle[i].F + cycle_size[to_cycle[i].S] << ' ';
    }

}
