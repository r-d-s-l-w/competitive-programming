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

struct edge{
    int from;
    int to;
    int cost;
    bool operator <(const edge& tmp){
        return cost < tmp.cost;
    }
};

vi parent, indeks;
int n, m, ctr;
ll res;
vector<edge> edgel;

void build_set(int x){
    parent[x] = x;
    indeks[x] = rand();
}
int find_set(int x){
    if (x == parent[x])
        return x;
    return parent[x] = find_set(parent[x]);
}
void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (indeks[a] < indeks[b])
            swap(a, b);
        parent[b] = a;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(2355);
    cin >> n >> m;
    parent.resize(n+1);
    indeks.resize(n+1);
    edgel.resize(m+1);
    for (int i=1; i<=n; ++i)
        build_set(i);
    for (int i=1; i<=m; ++i){
        cin >> edgel[i].from >> edgel[i].to >> edgel[i].cost;
    } sort(ALL(edgel));
    for (int i=1; i<=m; ++i){
        if (find_set(edgel[i].from) != find_set(edgel[i].to)){
            union_sets(edgel[i].from, edgel[i].to);
            res += edgel[i].cost;
            ++ctr;
        }
    }
    if (ctr != n-1) cout << "IMPOSSIBLE";
    else cout << res;
}
