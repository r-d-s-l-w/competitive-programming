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
 
int n, x;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> x;
 
    vector<pi> tab(n);
 
    for (int i=0; i<n; ++i){
        cin >> tab[i].F;
        tab[i].S = i+1;
    } sort(ALL(tab));
 
    int R = n - 1;
    for (int L=0; L<n; ++L){
        while (tab[L].F + tab[R].F > x && R != 0) --R;
        if (tab[L].F + tab[R].F == x && L != R) {
            cout << tab[L].S << ' ' << tab[R].S << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}
