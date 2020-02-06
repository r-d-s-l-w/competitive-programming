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

ll t, n, s, tab[100100], dp[100100];
pll maxx;
ll res;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> s;
        res = 0;
        maxx.F = 0;
        maxx.S = 0;
        for (int i=1; i<=n; ++i){
            cin >> tab[i];
            dp[i] = dp[i-1] + tab[i];
            if (tab[i] > maxx.F){
                maxx.F = tab[i];
                maxx.S = i;
            }
            if (dp[i] > s && dp[i] - maxx.F <= s)
                res = maxx.S;
        }
        cout << res << endl;
    }

}
