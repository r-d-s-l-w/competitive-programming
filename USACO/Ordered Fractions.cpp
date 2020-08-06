/*
ID: radek.m1
TASK: frac1
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

vector<pi> tab;
int n;

bool cmp(pi a, pi b){
    if ( (ld(a.F)/ld(a.S)) < (ld(b.F)/ld(b.S)) ) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    //freopen("frac1.in","r",stdin); freopen("frac1.out","w",stdout);
    cin >> n;
    tab.PB(MP(0,1));
    tab.PB(MP(1,1));
    for (int i=2; i<=n; ++i)
    for (int j=1; j<i; ++j)
        if (gcd(i,j)==1) tab.PB(MP(j,i));
    sort(ALL(tab),cmp);
    for (int i=0; i<tab.size(); ++i)
        cout << tab[i].F << '/' << tab[i].S << endl;
    return 0;
}
