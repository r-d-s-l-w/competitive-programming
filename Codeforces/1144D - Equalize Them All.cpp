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
 
int n, a[200100], bucket[200100], pos;
vi x,y,z;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        ++bucket[a[i]];
    }
 
    pi maxx = {-1,-1};
    for (int i=0; i<200100; ++i){
        if (bucket[i] > maxx.F){
            maxx.F = bucket[i];
            maxx.S = i;
        }
    }
    for (int i=1; i<=n; ++i){
        if (a[i] == maxx.S){
            pos = i;
            break;
        }
    }
    int i = pos;
    while (i > 1){
        if (a[i-1] > maxx.S){
            x.PB(2);
            y.PB(i-1);
            z.PB(i);
        }
        else if (a[i-1] < maxx.S){
            x.PB(1);
            y.PB(i-1);
            z.PB(i);
        }
        --i;
    }
    i = pos;
    while (i < n){
        if (a[i+1] > maxx.S){
            x.PB(2);
            y.PB(i+1);
            z.PB(i);
        }
        else if (a[i+1] < maxx.S){
            x.PB(1);
            y.PB(i+1);
            z.PB(i);
        }
        ++i;
    }
    //cout << maxx << endl;
    cout << x.size() << endl;
    for (int j=0; j<x.size(); ++j)
        cout << x[j] << ' ' << y[j] << ' ' << z[j] << endl;
 
 
 
    return 0;
}
