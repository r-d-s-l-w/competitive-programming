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
    int a, b;
    cin >> a >> b;
    if (a==b){
        cout << a << 8 << ' ' << b << 9 << endl;
    }
    else if (a+1 == b){
        cout << a << 9 << ' ' << b << 0 << endl;
    }
    else if (a == 9 && b == 1){
        cout << 9 << ' ' << 10 << endl;
    }
    else cout << -1 << endl;

}
