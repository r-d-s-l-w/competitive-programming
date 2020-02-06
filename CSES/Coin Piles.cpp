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
 
int t, a, b;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> t;
    while (t--){
        cin >> a >> b;
        if (2*a < b) cout << "NO\n";
        else if (2*b < a) cout << "NO\n";
        else if ((a+b)%3 != 0) cout << "NO\n";
        else cout << "YES\n";
    }
}
