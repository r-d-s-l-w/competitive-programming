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

int n,x,a,b;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cases;
    cin >> cases;
    while (cases--){
        cin >> n >> x >> a >> b;
        int A = min(a,b);
        int B = max(a,b);
        if (A - x <= 1){
            x -= A-1;
            A = 1;
        }
        else {
            A -= x;
            x = 0;
        }
        if (B+x >= n){
            B = n;
            x -= n-B;
        }
        else {
            B += x;
            x = 0;
        }
        cout << B - A << endl;
    }

}
