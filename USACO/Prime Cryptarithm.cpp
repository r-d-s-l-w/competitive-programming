/*
ID: radek.m1
TASK: crypt1
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
constexpr ll IN = 5000 + 10;
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

ll res, n, x;
bool tab[10];

bool xd(int i){
    if (i > 999) if (!tab[(i/1000)%10]) return 0;
    if (i > 99) if (!tab[(i/100)%10]) return 0;
    if (!tab[i%10]) return 0;
    if (!tab[(i/10)%10]) return 0;
    return 1;
}

bool cond(int i, int j){
    if (!xd(i) || i<100 || i>999) return 0;
    if (!xd(j) || j<10 || j>99) return 0;
    if (!xd(i*j) || i*j<1000 || i*j>9999) return 0;
    if (!xd(i*(j%10)) || i*(j%10)<100 || i*(j%10) > 999) return 0;
    if (!xd(i*(j/10)) || i*(j/10)<100 || i*(j/10) > 999) return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    freopen("crypt1.in","r",stdin); freopen("crypt1.out","w",stdout);
    cin >> n;
    REP(i,n){
        cin >> x;
        tab[x] = 1;
    }
    for (int i=10; i<100; ++i)
    for (int j=100; j<1000; ++j)
        if (cond(j,i)) ++res;

    cout << res << endl;
    return 0;
}
