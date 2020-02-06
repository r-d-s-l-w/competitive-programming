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
 
int n, m;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    multiset<int> s;
 
    cin >> n >> m;
    for (int i=0; i<n; ++i){
        int a;
        cin >> a;
        s.insert(a);
    }
    for (int i=0; i<m; ++i){
        int a;
        cin >> a;
        auto it = s.upper_bound(a);
        if (it != s.begin()){
            cout << *(--it) << endl;
            s.erase(it);
        }
        else cout << -1 << endl;
    }
 
}
