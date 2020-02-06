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
 
int z, n, m, dp[2010][2010], bucket[2010];
pi maxx;
bool tab[2010][2010];
char x;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> z;
    while (z--){
        cin >> n >> m;
        for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j){
            tab[i][j] = false;
            cin >> x;
            if (x == '.') tab[i][j] = true;
        }
        for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j){
            if (tab[i][j]) dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
            else dp[i][j] = 0;
            ++bucket[dp[i][j]];
        }
        for (int i=0; i<=min(n,m); ++i){
            if (bucket[i] != 0){
                maxx.F = i;
                maxx.S = bucket[i];
            }
            bucket[i] = 0;
        }
        cout << maxx.F << ' ' << maxx.S << endl;
    }
 
    return 0;
}
