/*
ID: radek.m1
TASK: sort3
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

int n, in, x, y, z, res, temp;
vi v;
int tab[4][4];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    freopen("sort3.in","r",stdin); freopen("sort3.out","w",stdout);
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> in;
        if (in == 1) ++x;
        else if (in == 2) ++y;
        else ++z;
        v.PB(in);
    }
    for (int i=0; i<x; ++i)
        ++tab[1][v[i]];
    for (int i=x; i<x+y; ++i)
        ++tab[2][v[i]];
    for (int i=x+y; i<x+y+z; ++i)
        ++tab[3][v[i]];

    for (int i=1; i<=3; ++i)
    for (int j=1; j<=3; ++j){
        if (i!=j && tab[i][j] > 0 && tab[j][i] > 0){
            int temp = min(tab[i][j],tab[j][i]);
            res += temp;
            tab[i][j] -= temp;
            tab[j][i] -= temp;
            tab[i][i] += temp;
            tab[j][j] += temp;
        }
    }
    int tp = x - tab[1][1];
    res += tp*2;
    cout << res << endl;
}
