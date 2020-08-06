/*
ID: radek.m1
TASK: combo
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

ll n, res;
ll tab[3][2];

ll dist(ll i, ll j){
    if (i > j) return min(i-j,j+n-i);
    return min(j-i,i+n-j);
}

bool corr(int i, int j, int k){
    if(dist(tab[0][0],i)<=2 && dist(tab[1][0],j)<=2 && dist(tab[2][0],k)<=2) return 1;
    if(dist(tab[0][1],i)<=2 && dist(tab[1][1],j)<=2 && dist(tab[2][1],k)<=2) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    //freopen("combo.in","r",stdin); freopen("combo.out","w",stdout);
    cin >> n;
    cin >> tab[0][0] >> tab[1][0] >> tab[2][0] >> tab[0][1] >> tab[1][1] >> tab[2][1];
    for (int i=1; i<=n; ++i)
    for (int j=1; j<=n; ++j)
    for (int k=1; k<=n; ++k)
        if (corr(i,j,k)) ++res;
    cout << res << endl;
    return 0;
}
