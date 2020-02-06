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
constexpr int INF = 1e9 + 1;
constexpr int IN = 1e6 + 10;
constexpr int MOD = 1e9 + 7;
constexpr ld EPS = 1e-9;
 
int z, n, tab[100100];
vi dp(100100,2*INF);
 
void find_solution(int x){
    int it = lower_bound(dp.begin(),dp.begin()+n,x) - dp.begin() - 1;
    //cout << it << endl;
    if (dp[it+1] > x) dp[it+1] = x;
}
 
void ini(){
    for (int i=1; i<=n; ++i)
        dp[i] = 2*INF;
    dp[0] = -2*INF;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    cin >> z;
    while(z--){
        cin >> n; ini();
        for(int i=1; i<=n; ++i)
            cin >> tab[i];
 
        for(int i=1; i<=n; ++i)
            find_solution(tab[i]);
 
        //for(int i=1; i<=n; ++i)
            //cout << dp[i] << ' ';
        for (int i=n; i>0; --i)
            if (dp[i] != 2*INF){
                cout << n - i << endl;
                break;
            }
 
    }
}
