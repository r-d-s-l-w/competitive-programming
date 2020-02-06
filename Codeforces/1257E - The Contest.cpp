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

int k1,k2,k3,tmp;
int K1[600200], K2[600200], K3[600200];
int dp[600600][3];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k1 >> k2 >> k3;
    int n = k1+k2+k3;
    for (int i=0; i<k1; ++i){
        cin >> tmp;
        K1[tmp] = 1;
    }
    for (int i=0; i<k2; ++i){
        cin >> tmp;
        K2[tmp] = 1;
    }
    for (int i=0; i<k3; ++i){
        cin >> tmp;
        K3[tmp] = 1;
    }

    for (int i=1; i<=n; ++i){
        if (K1[i]){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = min(dp[i-1][1],dp[i-1][0]) + 1;
            dp[i][2] = min(dp[i-1][2],min(dp[i-1][1],dp[i-1][0])) + 1;
        }
        else if (K2[i]){
            dp[i][0] = dp[i-1][0] + 1;
            dp[i][1] = min(dp[i-1][1],dp[i-1][0]);
            dp[i][2] = min(dp[i-1][2],min(dp[i-1][1],dp[i-1][0])) + 1;
        }
        else {
            dp[i][0] = dp[i-1][0] + 1;
            dp[i][1] = min(dp[i-1][1],dp[i-1][0]) + 1;
            dp[i][2] = min(dp[i-1][2],min(dp[i-1][1],dp[i-1][0]));
        }
    }

    cout << min(min(dp[n][0],dp[n][1]),dp[n][2]) << endl;


}
