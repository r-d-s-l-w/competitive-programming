/// Radoslaw Mysliwiec 2020
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using vll = vector<ll>;

ll t, a, b, c;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll s;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        s = a+b+c;
        if (max(a,max(b,c)) > (s+1)/2)
            cout << "No\n";
        else cout << "Yes\n";
    }

}
