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
using matrix = vector<vll>;
 
set<pi> s;
priority_queue<int> pq;
map<int,int> vis;
int x, n;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> x;
    s.insert({0,x});
    cin >> n;
    while (n--){
        int a;
        cin >> a;
        auto it = s.upper_bound({a, 0});
        pi tmp = *(--it);
        s.erase(it);
        vis[tmp.S - tmp.F]++;
        s.insert({tmp.F, a});
        s.insert({a, tmp.S});
        pq.push(a - tmp.F);
        pq.push(tmp.S - a);
        while(vis[pq.top()] > 0){
            --vis[pq.top()];
            pq.pop();
        } cout << pq.top() << ' ';
    }
 
}
