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
 
int n;
priority_queue<int, vi, greater<int>> pq;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n;
    vector<pi> start(n), stop(n);
    vi nr(n, -1);
 
    for (int i=0; i<n; ++i){
        pq.push(i);
        int a, b;
        cin >> a >> b;
        start[i] = {a, i};
        stop[i] = {b, i};
    } sort(ALL(start)); sort(ALL(stop));
 
    int it = 0;
    for (int i=0; i<n; ++i){
        while(it < n && stop[it].F < start[i].F){
            pq.push(nr[stop[it].S]);
            ++it;
        }
        nr[start[i].S] = pq.top();
        pq.pop();
    }
 
    cout << *max_element(ALL(nr)) + 1 << endl;
    for (int i=0; i<n; ++i)
        cout << nr[i] + 1 << ' ';
}
 
 
Test details
Test 1
Verdict: ACC
