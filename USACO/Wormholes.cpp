/*
ID: radek.m1
TASK: wormhole
LANG: C++11
*/
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
#define REP(i,n) for (int i = 1; i <= n; ++i)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;

constexpr ll MOD = 1000000007;
constexpr ll INI = -1;
constexpr ll IN = 350 + 10;
constexpr ll INF = 1e9 + 1;
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

ll n,res;
pll tab[30];
vll adj[30];
ll paired[30];

void is_cycle(){
    int maks = 0;
    for (int i=0; i<n; ++i){
        int k = i;
        int j = 0;
        for (j; j<n; ++j){
            if (tab[k+1].F != tab[k].F) break;
            k = paired[k+1];
        }
        maks = max(j,maks);
    }
    if (maks == n) ++res;
}

void sol(){
    int k;
    for (k=0; k<n; ++k)
        if (paired[k] == INI)
            break;
    if (k == n) is_cycle();

    for (int i=0; i<n; ++i){
        if (i!=k && paired[i] == INI){
            paired[i] = k;
            paired[k] = i;
            sol();
            paired[i] = paired[k] = INI;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    //freopen("wormhole.in","r",stdin); freopen("wormhole.out","w",stdout);
    cin >> n;
    for (int i=0; i<n; ++i) paired[i] = INI;
    for (int i=0; i<n; ++i)
        cin >> tab[i].S >> tab[i].F ;
    sort(tab,tab+n);
    sol();
    cout << res << endl;
    return 0;
}
