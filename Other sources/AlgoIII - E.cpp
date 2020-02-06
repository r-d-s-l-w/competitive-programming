/// Radoslaw Mysliwiec 2019
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
 
constexpr int INI = -1;
constexpr int INF = 1e9 + 1;
constexpr int IN = 1e6 + 10;
constexpr int MOD = 1e9 + 7;
constexpr ld EPS = 1e-9;
 
int z, k, tab[1000100];
ll suma;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    cin >> z;
    while (z--){
        suma = 0;
        cin >> k;
        for (int i=0; i<k; ++i){
            cin >> tab[i];
        }
        sort(tab,tab+k);
        reverse(tab,tab+k);
        ll tmp = 0;
        for (int i=0; i<k; ++i){
            tmp += tab[i] - i;
            suma = max(suma,tmp);
        }
        cout << suma << endl;
    }
}
