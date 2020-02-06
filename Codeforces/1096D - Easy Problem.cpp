/// Radoslaw Mysliwiec 2019
#pragma GCC optimize("O3")
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
 
constexpr int INI = -1;
 
int n;
ll tab[100100], dp[100100][4];
char s[100100];
string hard = "hard";
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s+1;
    for (int i=1; i<=n; ++i)
        cin >> tab[i];
 
    for (int i=1; i<=n; ++i)
    for (int j=0; j<4; ++j){
        if (hard[j] == s[i]){
            dp[i][j] = dp[i-1][j] + tab[i];
            if (j != 0 && dp[i][j] > dp[i-1][j-1]) dp[i][j] = dp[i-1][j-1];
        }
        else dp[i][j] = dp[i-1][j];
    }
 
    cout << min(min(dp[n][0],dp[n][1]),min(dp[n][2],dp[n][3]));
 
}
