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
 
constexpr int INF = 1e9;
 
void solve(){
    int n;
    vll res(255000, 0);
    vector<vi> plane(2550, vi(2550, 0));
    cin >> n; vector<pi> points(n+1);
    for (int i=1; i<=n; ++i){
        int x, y;
        cin >> x >> y;
        plane[x][y] = i;
        points[i] = {x,y};
    }
 
    for (int i=1; i<=n; ++i){
        vi dist(n+1, INF);
        queue<pi> q;
        q.push(points[i]);
        dist[i] = 0;
        vector<pi> edgel;
 
        for (int j=1; j<=n; ++j)
            if (i != j) edgel.PB(points[j]);
 
        while(!q.empty()){
            pi tmp = q.front(); q.pop();
            assert(dist[plane[tmp.F][tmp.S]] != INF);
            for (int j=0; j<edgel.size(); ++j){
                if ((edgel[j].F > tmp.F && edgel[j].S > tmp.S) ||
                    (edgel[j].F < tmp.F && edgel[j].S < tmp.S)){
                        dist[plane[edgel[j].F][edgel[j].S]] = dist[plane[tmp.F][tmp.S]] + 1;
                        swap(edgel[j], edgel.back());
                        q.push(edgel.back());
                        edgel.pop_back();
                        --j;
                    }
            }
        }
        ll sum = 0;
        for (int j=1; j<=n; ++j)
            sum += dist[j];
        res[i] = sum;
    }
 
    for (int i=1; i<=n; ++i)
        cout << res[i] << endl;
 
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int z;
    cin >> z;
    while (z--){
        solve();
    }
}
