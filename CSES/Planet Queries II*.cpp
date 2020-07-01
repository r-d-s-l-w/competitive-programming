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

int n, a, b, q, maxTwoPower, res;
vector<bool> visited;
matrix fast;
vi id;

int go(int v, int k){
    for (int i=maxTwoPower; i>=0; --i){
        if (k&(1<<i)) v = fast[i][v];
    }
    return v;
}

void dfs(int v){
    if (visited[v]) return;
    visited[v] = 1;
    dfs(fast[0][v]);
    id[v] = id[fast[0][v]] + 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    maxTwoPower = 32 - __builtin_clz(n - 1);
    id.resize(n+1, 0);
    fast.resize(maxTwoPower+1, vi(n+1));
    visited.resize(n+1, 0);

    for (int i=1; i<=n; ++i){
        cin >> a;
        fast[0][i] = a;
    }

    for (int i=1; i<=maxTwoPower; ++i){
        for (int j=1; j<=n; ++j){
            fast[i][j] = fast[i-1][fast[i-1][j]];
        }
    }

    for (int i=1; i<=n; ++i)
        dfs(i);

    while (q--){
        cin >> a >> b; res = 0;
        for (int i=0; i<2; ++i){
            if (id[a] > id[b]){
                res += id[a] - id[b];
                a = go(a, id[a] - id[b]);
            }
            if (a == b) {
                cout << res << endl;
                goto next;
            }
            res += id[a];
            a = go(a, id[a]);
        }
        cout << -1 << endl;
        next: ;
    }
}
