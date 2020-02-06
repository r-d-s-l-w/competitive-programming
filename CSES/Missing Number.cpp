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
vector<bool> tab(200100, 0);
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n;
 
    for (int i=1; i<n; ++i){
        int x;
        cin >> x;
        tab[x] = true;
    }
 
    for (int i=1; i<=n; ++i){
        if (!tab[i]) {
            cout << i << endl;
            return 0;
        }
    }
}
