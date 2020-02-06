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

int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cases;
    cin >> cases;
    while (cases--){
        ll x,y;
        cin >> x >> y;
        bool poss = 1;
        if (x >= y){
            cout << "YES\n";
        }
        else {
            int it = 0;
            while (x < y){
                if (x <= 0){
                    poss = 0;
                    break;
                }
                if (x%2 == 0) x = (3*x)/2;
                else if (x > 1) x--;
                else {
                    poss = 0;
                    break;
                }
                ++it;
                if (it > 10000) {
                    poss = 0;
                    break;
                }
            }
            if (poss == 1) cout << "YES\n";
            else cout << "NO\n";
        }

    }
}
