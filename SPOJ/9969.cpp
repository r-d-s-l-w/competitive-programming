/// Radoslaw Mysliwiec 2019
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
#define REP(i,x) for(int i=1; i<=x; ++i)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;

constexpr ll INI = -1;
constexpr ll INF = 1e8 + 1;
constexpr ll IN = 1e5 + 100;
constexpr ll MOD = 1;
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

int N, T, P, Q, g[160][160], res[160][160][160], tab[160];

void solve(){
    REP(k,P){
        REP(i,N) REP(j,N)
            res[i][j][k] = res[i][j][k-1];
        REP(i,N) REP(j,N)
            res[i][j][k] = min(res[i][tab[k]][k] + res[tab[k]][j][k], res[i][j][k]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    ///freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    cin >> T;
    REP(xd,T){
        cin >> N;
        for (int i=1; i<N; ++i)
        for (int j=i+1; j<=N; ++j){
            cin >> g[i][j];
            if (g[i][j] == -1) g[i][j] = INF;
            g[j][i] = g[i][j];
            res[i][j][0] = g[i][j];
            res[j][i][0] = g[j][i];
        }
        ///REP(i,4) {REP(j,4) cout << res[i][j][0] << ' '; cout << endl;}
        cin >> P;
        for (int i=1; i<=P; ++i)
            cin >> tab[i];
        solve();
        cin >> Q;
        int k, a, b;
        cout << "Case " << xd << ":";
        while (Q--){
            cin >> k >> a >> b;
            if (res[a][b][k] > 1e7) cout << ' ' << -1;
            else cout << ' ' << res[a][b][k];
        }
        cout << endl;
    }
    return 0;
}
