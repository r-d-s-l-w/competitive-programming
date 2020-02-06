/// Radoslaw Mysliwiec 2020
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
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
 
vector<tuple<int,int,int>> edgel;
vector<ll> dist(2550, 1e18);
vector<int> from(2550, -1);
vector<int> res;
int n, m;
 
int bellman_ford(int s){
    dist[s] = 0; int cycle;
    for (int i=0; i<n; ++i){
        cycle = -1;
        for (auto u: edgel){
            if (dist[get<1>(u)] > dist[get<0>(u)] + get<2>(u)){
                dist[get<1>(u)] = dist[get<0>(u)] + get<2>(u);
                from[get<1>(u)] = get<0>(u);
                cycle = get<1>(u);
            }
        }
    }
    return cycle;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
 
    for (int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        tuple<int, int, int> tmp{a, b, c};
        edgel.PB(tmp);
    }
 
    int node = bellman_ford(1);
 
    if (node == -1) {
        cout << "NO\n";
        return 0;
    }
 
    cout << "YES\n";
 
    for (int i=0; i<n; ++i)
        node = from[node];
 
    int tmp = node;
    res.PB(tmp);
 
    do {
        tmp = from[tmp];
        res.PB(tmp);
    } while (tmp != node);
 
    reverse(ALL(res));
    for (auto u: res)
        cout << u << ' ';
    cout << endl;
}
