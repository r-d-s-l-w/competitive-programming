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
 
constexpr ll INF = 1e18 + 1;
 
ll z, n, k, dp[510][510], tab[510];
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> z;
    while (z--){
        cin >> n >> k;
        for (int i=1; i<=k; ++i)
            cin >> tab[i]; tab[0] = 0; tab[k+1] = n;
        sort(tab,tab+k+1);
 
        for (int i=2; i<=k+1; ++i)
        for (int j=0; j<=k-i+1; ++j){
            dp[j][j+i] = INF;
            for (int a=1; a<i; ++a){
                dp[j][j+i] = min(dp[j][j+i], dp[j][j+a] + dp[j+a][j+i]
                           + max(tab[j+a] - tab[j], tab[j+i] - tab[j+a]));
            }
        }
        cout << dp[0][k+1] << endl;
 
    }
    return 0;
}
