// Radoslaw Mysliwiec 2019
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
 
ll z, n, pos[1000100], kara[1000100], dp[1000100], len, cena;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> z;
    while (z--){
        cin >> n;
        for (int i=1; i<=n; ++i)
            cin >> pos[i] >> kara[i];
        cin >> len >> cena;
        int it = 0;
        for (int i=1; i<=n; ++i){
            while(pos[it + 1] < pos[i] - len) ++it;
            dp[i] = min(dp[i-1] + kara[i], dp[it] + cena);
        }
        cout << dp[n] << endl;
    }
 
    return 0;
}
