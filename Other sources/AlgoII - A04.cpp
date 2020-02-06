#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
using ll = long long;
 
constexpr ll INF = 1e9 + 1;
 
ll dp[2010][2010], z, n, d[2010], t[2010];
 
void ini(){
    for (int i=0; i<=n; ++i)
    for (int j=0; j<=n; ++j)
        dp[i][j] = INF;
 
    for (int i=1; i<=n; ++i)
        dp[i][i] = 0;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> z;
    while (z--){
        cin >> n;
        ini();
        for (int i=1; i<=n; ++i)
            cin >> d[i] >> t[i];
 
        bool poss = true;
 
        for (int i=1; i<n; ++i){
            for (int j=1; j<=n-i; ++j){
                dp[j][j+i] = dp[j][j+i-1] + d[j+i] - d[j+i-1];
                if (dp[j][j+i] >= t[j+i])
                    dp[j][j+i] = INF;
            }
            for (int j=n; j>i; --j){
                dp[j][j-i] = dp[j][j-i+1] + d[j-i+1] - d[j-i];
                if (dp[j][j-i] >= t[j-i])
                    dp[j][j-i] = INF;
            }
            for (int j=1; j<=n-i; ++j){
                if (dp[j][j+i] == INF && dp[j+i][j] == INF)
                    poss = false;
                else if (dp[j][j+i] == INF)
                    dp[j][j+i] = dp[j+i][j] + d[j+i] - d[j];
                else if (dp[j+i][j] == INF)
                    dp[j+i][j] = dp[j][j+i] + d[j+i] - d[j];
            }
        }
 
        if (poss == false)
            cout << "FAIL\n";
        else cout << min(dp[1][n],dp[n][1]) << endl;
 
    }
 
}
