/// Radoslaw Mysliwiec 2019
#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

#define F first
#define S second
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
#define DEBUG(x) cout << '>' << #x << ": " << x << endl;
#define REP(i,n) for (int i = 1; i <= n; ++i)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;

constexpr ll MOD = 1000000007;
constexpr ll INI = -1;
constexpr ll IN = 3*100000 + 10;
constexpr ll INF = 1e18 + 1;
constexpr ld EPS = 1e-9;

ll q, n, a[IN], b[IN];
ll dp[IN][3];
ll res;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    cin >> q;
    while (q--){
        cin >> n; res = 0;
        for (int i=0; i<n; ++i){
            cin >> a[i] >> b[i];
            dp[i][0] = INF;
            dp[i][1] = INF;
            dp[i][2] = INF;
        }

        dp[0][0] = 0;
        dp[0][1] = b[0];
        dp[0][2] = 2*b[0];

        for (int i=1; i<n; ++i)
        for (int j=0; j<3; ++j){
            if (a[i] == a[i-1]){
                if (j == 0) dp[i][j] = min(dp[i-1][1],dp[i-1][2]) + j*b[i];
                else if (j == 1) dp[i][j] = min(dp[i-1][0],dp[i-1][2]) + j*b[i];
                else dp[i][j] = min(dp[i-1][0],dp[i-1][1]) + j*b[i];
            }
            else { // 1 2
                if (a[i]+j != a[i-1]){ dp[i][j] = min(dp[i][j],dp[i-1][0]+ j*b[i]);}
                if (a[i]+j != a[i-1] + 1) {dp[i][j] = min(dp[i][j],dp[i-1][1]+ j*b[i]) ;}
                if (a[i]+j != a[i-1] + 2){ dp[i][j] = min(dp[i][j],dp[i-1][2]+ j*b[i]) ;}
            }/*
            if (a[i] == a[i-1]){
                dp[i][0] = min(dp[i-1][1],dp[i-1][2]);
                dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + b[i];
                dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + 2*b[i];
            }
            else {
                dp[i][0] = min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]));
                if ()dp[i][1] = min(dp[])
            }*/
        }
        //for (int i=0; i<n; ++i){
       //     cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
       // }
        cout << min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2])) << endl;
    }

    return 0;
}
