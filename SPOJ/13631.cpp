#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
#define DEBUG(x) cout << '>' << #x << ": " << x << endl;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;

constexpr ll MOD = 1;
constexpr ll IN = 110;
constexpr ll INI = -1;
constexpr ll INF = 1e9 + 1;
constexpr ld EPS = 1e-9;

inline ll two(ll n) {return 1<<n;}
inline bool EQ(ld a, ld b) {return fabs(a-b)<EPS;}
inline bool is_set(ll n, ll k) {return (n>>k)&1;}
inline void set_bit(ll &n, ll k) {n|=two(k);}
inline void unset_bit(ll &n, ll k) {n&=~two(k);}
inline ll last_bit(ll n) {return n&(-n);}
inline ll ones(ll n) {ll res=0;while(n&&++res)res-=last_bit(n);return res;}
inline ll gcd(ll a, ll b) {return b==0?a:gcd(b,a%b);}
inline ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

ll n, tab[110], dp[110][110][110];

ll sol(ll pos, ll i, ll j){
    if (pos >= n) return 0;
    if (dp[pos][i][j] != 0) return dp[pos][i][j];
    if (tab[pos] > tab[i] && tab[pos] < tab[j]) return dp[pos][i][j] = max(sol(pos+1,pos,j) + 1, max(sol(pos+1,i,j), sol(pos+1,i,pos) + 1));
    else if (tab[pos] > tab[i]) return dp[pos][i][j] = max(sol(pos+1,pos,j) + 1, sol(pos+1,i,j));
    else if (tab[pos] < tab[j]) return dp[pos][i][j] = max(sol(pos+1,i,pos) + 1, sol(pos+1,i,j));
    return dp[pos][i][j] = sol(pos+1,i,j);
}

void ini(){
    for (int i=0; i<110; ++i){
        tab[i] = 0;
        for (int j=0; j<110; ++j)
        for (int k=0; k<110; ++k)
            dp[i][j][k] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    ///freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    ll t;
    cin >> t;
    while (t--){
        cin >> n;
        ini();
        tab[105] = INF;
        tab[106] = -INF;
        for (int i=0; i<n; ++i)
            cin >> tab[i];
        cout << sol(0,106,105) << endl;
    }
}
