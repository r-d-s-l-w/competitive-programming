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

vi nextt, col, id, res;
int t, n, a, cycle, tmp;

void dfs(int v){
    if (col[v]) return;
    col[v] = 1;
    id[v] = ++t;
    dfs(nextt[v]);
    if (col[nextt[v]] == 1) {
        cycle = id[v] - id[nextt[v]] + 1;
        tmp = cycle;
    }
    if (tmp > 0) {
        res[v] = cycle;
        --tmp;
    }
    else res[v] = res[nextt[v]] + 1;
    col[v] = 2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    nextt.resize(n+1, 0);
    id.resize(n+1, 0);
    col.resize(n+1, 0);
    res.resize(n+1, 0);
    for (int i=1; i<=n; ++i){
        cin >> a;
        nextt[i] = a;
    }
    for (int i=1; i<=n; ++i){
        dfs(i);
        cout << res[i] << ' ';
    }
}
