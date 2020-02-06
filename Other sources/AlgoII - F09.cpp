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
 
inline ll two(ll n) {return 1<<n;}
inline bool EQ(ld a, ld b) {return fabs(a-b)<EPS;}
inline bool is_set(ll n, ll k) {return (n>>k)&1;}
inline void set_bit(ll &n, ll k) {n|=two(k);}
inline void unset_bit(ll &n, ll k) {n&=~two(k);}
inline ll last_bit(ll n) {return n&(-n);}
inline ll ones(ll n) {ll res=0;while(n&&++res)n-=last_bit(n);return res;}
inline ll gcd(ll a, ll b) {return b==0?a:gcd(b,a%b);}
inline ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}
 
int z, n, m, a, b;
bool graph[20][20];
vi dp[20][100000];
 
void ini(){
    for(int i=0; i<20; ++i)
    for(int j=0; j<20; ++j)
        graph[i][j] = 0;
    for(int i=0; i<=n; ++i)
    for(int j=0; j<=(2<<n); ++j)
        dp[i][j].clear();
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    cin >> z;
    while(z--){
        cin >> n >> m; ini();
        for (int i=0; i<m; ++i){
            cin >> a >> b;
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
 
        for (int i=1; i<=n; ++i)
            if (graph[0][i]) dp[i][1<<(i-1)].PB(i);
 
        for (int i=0; i<(1<<n); ++i){
            for (int j=1; j<=n; ++j){
                for (int k=1; k<=n; ++k){
                    if ((i & (1<<(k-1))) == 0 && graph[j][k] && !dp[j][i].empty()){
                        dp[k][i|(1<<(k-1))] = dp[j][i];
                        dp[k][i|(1<<(k-1))].PB(k);
                    }
                }
            }
        }
        int res = -1;
        for (int i=1; i<=n; ++i){
            if (!dp[i][(1<<n)-1].empty() && graph[0][i]){
                res = i;
                break;
            }
        }
        if (res == -1) cout << "NIE\n";
        else {
            cout << "TAK\n";
            for (auto u: dp[res][(1<<n)-1])
                cout << u << ' '; cout << endl;
        }
    }
}
