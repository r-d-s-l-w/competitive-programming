// Radoslaw Mysliwiec 2019
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
 
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
using pll = pair<ll,ll>;
using matrix = vector<vll>;
 
constexpr int INF = 1e9 + 1;
 
int n, tab[200200], res;
 
int one,two;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
 
    for (int i=0; i<n; ++i){
        cin >> tab[i];
        if (tab[i] == 0) ++one;
        else ++two;
 
    }
    for (int i=0; i<n; ++i){
        if (tab[i] == 0) --one;
        else --two;
        if (one == 0 || two == 0){
            cout << i+1 << endl;
            break;
        }
    }
    return 0;
}
