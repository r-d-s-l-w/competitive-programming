/*
ID: radek.m1
TASK: milk3
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

int a, b, c;
bool vis[21][21][21];
bool res[21];

pi stan(int x, int y, int Y){
    pi res;
    if (Y-y < x) {res.F = x - Y + y; res.S = y + x - res.F;}
    if (Y-y >= x) {res.F = 0; res.S = y + x;}
    return res;
}

void sol(int x, int y, int z){
    if (vis[x][y][z]) return;
    vis[x][y][z] = true;
    if (x == 0) res[z] = 1;
    pi xy = stan(x,y,b), yx = stan(y,x,a);
    pi yz = stan(y,z,c), zy = stan(z,y,b);
    pi xz = stan(x,z,c), zx = stan(z,x,a);
    sol(xy.F,xy.S,z);
    sol(yx.S,yx.F,z);
    sol(xz.F,y,xz.S);
    sol(zx.S,y,zx.F);
    sol(x,yz.F,yz.S);
    sol(x,zy.S,zy.F);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    freopen("milk3.in","r",stdin); freopen("milk3.out","w",stdout);
    cin >> a >> b >> c;
    sol(0,0,c);
    bool xd = 0;
    for (int i=0; i<=c; ++i){
        if(res[i] && xd) cout << ' ' << i;
        else if(res[i]) {cout << i; xd=1;}
    }
    cout << endl;
    return 0;
}
