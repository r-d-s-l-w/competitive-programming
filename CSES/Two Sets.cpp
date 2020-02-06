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
 
ll n;
vi a, b;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n;
    ll sum = ((1+n)*n)/2;
    if (sum % 2) {
        cout << "NO\n";
        return 0;
    }
    sum /= 2;
    for (int i=n; i>=1; --i){
        if (sum >= i){
            a.PB(i);
            sum -= i;
        }
        else b.PB(i);
    }
    cout << "YES\n";
    cout << a.size() << endl;
    for (auto u: a){
        cout << u << ' ';
    } cout << endl;
    cout << b.size() << endl;
    for (auto u: b)
        cout << u << ' ';
    cout << endl;
}
