/// Radoslaw Mysliwiec 2020
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
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
 
vector<pi> tab;
int n;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    tab.PB({0, 0});
    cin >> n;
    for (int i=1; i<=n; ++i){
        int a;
        cin >> a;
        while(tab.back().F >= a)
            tab.pop_back();
        cout << tab.back().S << ' ';
        tab.PB({a, i});
    }
}
Tes
