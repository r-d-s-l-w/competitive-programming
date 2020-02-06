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
#define dd cout << " debug";
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;
using ordered_set = tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update>;
 
int n, a, b;
vi tab(200200);
vll pref(200200, 0);
ll res = -1e18;
priority_queue<pll, vector<pll>, greater<pll>> pq;
vector<bool> used(200200, 0);
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> a >> b;
    for (int i=1; i<=n; ++i){
        cin >> tab[i];
        pref[i] = pref[i-1];
        pref[i] += tab[i];
    }
 
    for (int i=1; i<=n; ++i){
        if (i - a >= 0) pq.push({pref[i - a], i - a});
 
        if (i - b > 0) used[i - b - 1] = true;
 
        while(!pq.empty() && used[pq.top().S])
            pq.pop();
 
        if (i >= a) res = max(res, pref[i] - pq.top().F);
    }
 
    cout << res << endl;
}
