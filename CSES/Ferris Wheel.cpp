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
 
int n, x, res;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> x;
    vi tab(n);
    for (int i=0; i<n; ++i)
        cin >> tab[i];
    sort(ALL(tab));
    int L = 0, R = n-1;
    while(L <= R){
        if (tab[L] + tab[R] <= x) {
            ++L;
            --R;
        }
        else --R;
        ++res;
    }
 
    cout << res << endl;
 
}
