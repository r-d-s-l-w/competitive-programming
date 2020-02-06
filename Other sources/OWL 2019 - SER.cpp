#include <bits/stdc++.h>
#pragma GCC optimize("O3")
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
using ll = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
 
ll T, k, a, b, A, B;
 
ll solve(){
    ll res = 0;
    if (k%2){
        A = k; B = k;
    }
    else {
        A = k; B = k+1;
    }
 
    while (A <= b){
        if (A <= a && B >= b)
            res += b - a + 1;
        else if (A >= a && B <= b)
            res += B - A + 1;
        else if (A < a && B >= a)
            res += B - a + 1;
        else if (A <= b && B > b)
            res += b - A + 1;
        A *= 2; B *= 2; ++B;
    }
 
    return res;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--){
        cin >> k >> a >> b;
        if (k == 0) cout << b - a + 1 << endl;
        else cout << solve() << endl;
    }
    return 0;
}
