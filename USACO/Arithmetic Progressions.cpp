/*
ID: radek.m1
TASK: ariprog
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

bool is_bisquare[150000];
int n,m;
vector<pi> tab;

void dfs(int x, int a, int b){
    if (x == n) {
        tab.PB(MP(b,a));
        return;
    }
    if (is_bisquare[x*b+a]) dfs(x+1,a,b);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    freopen("ariprog.in","r",stdin); freopen("ariprog.out","w",stdout);
    cin >> n >> m;
    for (int i=0; i<=m; ++i)
    for (int j=0; j<=m; ++j)
        is_bisquare[i*i+j*j] = 1;
    //for (int i=0; i<=2*m*m; ++i) cout << i << ' ' << is_bisquare[i] << endl;

    for (int i=0; i<=m*m; ++i)
        if (is_bisquare[i])
            for (int j=1; j<=(2*m*m)/(n-1); ++j)
                dfs(1,i,j);
    sort(ALL(tab));
    for (int i=0; i<tab.size(); ++i)
        cout << tab[i].S << ' ' << tab[i].F << endl;
    if (tab.size()==0) cout << "NONE\n";
    return 0;
}
