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

vi parent, indeks;
int n, m, ctr, res = 1;

void build_set(int x){
    parent[x] = x;
    indeks[x] = 1;
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
        indeks[a] += indeks[b];
        res = max(res, indeks[a]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    parent.resize(n+1);
    indeks.resize(n+1);
    for (int i=1; i<=n; ++i)
        build_set(i);
    for (int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        if (find_set(a) != find_set(b)){
            --n;
            union_sets(a, b);
        }
        cout << n << ' ' << res << endl;
    }
}
