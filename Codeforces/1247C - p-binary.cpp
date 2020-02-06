/// Radoslaw Mysliwiec 2019
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

ll n, p;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cases;
    cin >> n >> p;

    for (int i=1; i<40; ++i){
        ll tmp = n - i*p;
        if (n > 0 && __builtin_popcount(tmp) <= i && i <= tmp){
            cout << i << endl;
            return 0;
        }

    }
    cout << -1 << endl;

}
