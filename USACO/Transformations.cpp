/*
ID: radek.m1
TASK: transform
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
using vc = vector<char>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vc>;

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

int n;

matrix rotation(matrix a){
    matrix b(n,vc(n));
    for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
        b[i][j] = a[j][n-i-1];
    return b;
}

matrix reflection(matrix a){
    matrix b(n,vc(n));
    for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
        b[i][j] = a[i][n-j-1];
    return b;
}

bool eq(matrix a, matrix b){
    for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
        if (a[i][j] != b[i][j]) return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    freopen("transform.in","r",stdin); freopen("transform.out","w",stdout);
    cin >> n;
    vi ans;
    matrix a(n,vc(n));
    matrix b(n,vc(n));
    matrix c(n,vc(n));
    for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
        cin >> a[i][j];
    for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
        cin >> c[i][j];
    a = rotation(a);
    if (eq(a,c)) ans.PB(3);
    a = rotation(a);
    if (eq(a,c)) ans.PB(2);
    a = rotation(a);
    if (eq(a,c)) ans.PB(1);
    a = rotation(a);
    if (eq(a,c)) ans.PB(6);
    a = reflection(a);
    if (eq(a,c)) ans.PB(4);
    a = rotation(a);
    if (eq(a,c)) ans.PB(5);
    a = rotation(a);
    if (eq(a,c)) ans.PB(5);
    a = rotation(a);
    if (eq(a,c)) ans.PB(5);

    if (ans.empty()) cout << 7 << endl;
    else {
        sort(ALL(ans));
        cout << ans[0] << endl;
    }

    return 0;
}
