// Radoslaw Mysliwiec 2019
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB emplace_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;
 
int n, res;
int a[2010], i, j;
vi x, y;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        if (a[i]%2) y.PB(a[i]);
        else x.PB(a[i]);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    if (y.size() == x.size()) res = 0;
    else if (y.size() > x.size()){
        for (int i=0; i<y.size()-x.size() - 1; ++i)
            res += y[i];
    }
    else if (x.size() > y.size()){
        for (int i=0; i<x.size()-y.size() - 1; ++i)
            res += x[i];
    }
 
    cout << res << endl;
 
    return 0;
}
