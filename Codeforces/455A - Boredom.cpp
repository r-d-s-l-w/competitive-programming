#include <bits/stdc++.h>
#pragma GCC optimize("O3")
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
 
constexpr int MOD = 1;
constexpr int IN = 2000 + 10;
constexpr int INF = 1e9 + 1;
constexpr ld EPS = 1e-9;
 
ll n, x, maxx;
ll cnt[100100];
ll dp[100100];
 
ll sol(int a){
    if (dp[a] != -1) return dp[a];
    if (a == 0) return 0;
    if (a == 1) return cnt[a];
    return dp[a] = max(sol(a-1), sol(a-2) + cnt[a]*a);
}
 
void ini(){
    for (int i=0; i<100001; ++i)
        dp[i] = -1;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    ini();
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> x;
        ++cnt[x];
        maxx = max(maxx, x);
    }
    cout << sol(maxx) << endl;
    return 0;
}
