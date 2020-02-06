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
 
int i;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> i;
 
    for (ll n=1; n<=i; ++n){
        if (n == 1) cout << 0 << endl;
        else if (n == 2) cout << 6 << endl;
        else if (n == 3) cout << 28 << endl;
        else if (n == 4) cout << 96 << endl;
        else cout << ((((n-4)*(n-4))*(n*n-9)) + (4*(n-4)*(n*n-7)) + 4*(n*n-5) + 4*(n*n-3) + 8*(n*n-4) + 4*(n-4)*(n*n-5)) / 2 << endl;
    }
 
 
}
