/*
ID: radek.m1
TASK: queen
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

ll n, res;
ll tab[100];
bool diag1[100], diag2[100], row[100], col[100];

void dfs(int x){
    if (x == 0) {++res; if (res%1000==0) cout << res << endl; return;}

    for (int i=1; i<=n; ++i){
        if (!col[i] && !row[x] && !diag1[n+i-x] && !diag2[x+i]){
            col[i] = row[x] = diag1[n+i-x] = diag2[x+i] = 1;
            dfs(x-1);
            col[i] = row[x] = diag1[n+i-x] = diag2[x+i] = 0;
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    //freopen("queen.in","r",stdin); freopen("queen.out","w",stdout);
    cin >> n;
    dfs(n);
    cout << res << endl;
    return 0;
}
