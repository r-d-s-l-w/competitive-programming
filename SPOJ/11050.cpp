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
#define REP(i,n) for (int i = 0; i < n; ++i)

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

ll T, N, result;

matrix mul(matrix a, matrix b){
    matrix res(10,vll(10,0));
    REP(i,10) REP(j,10) REP(k,10)
        res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
    return res;
}

matrix pow(matrix a, int n){
    if (n == 1) return a;
    if (n % 2) return mul(pow(a,n-1),a);
    matrix res = pow(a,n/2);
    return mul(res,res);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    ///freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    vll start = {4,4,3,4,3,3,2,3,3,4};
    matrix exp = {
        {1,1,0,1,0,1,0,0,0,0},
        {1,0,1,0,1,0,0,0,1,0},
        {0,1,0,1,0,0,0,1,0,0},
        {1,0,1,0,0,0,1,0,1,0},
        {0,1,0,0,0,1,0,1,0,0},
        {1,0,0,0,1,0,1,0,0,0},
        {0,0,0,1,0,1,0,0,0,0},
        {0,0,1,0,1,0,0,0,1,0},
        {0,1,0,1,0,0,0,1,0,0},
        {1,1,1,1,1,1,1,1,1,1},
    };
    cin >> T;
    while (T--){
       cin >> N; result = 0;
       if (N > 1){
       matrix temp = pow(exp,N-1);
       for (int i=0; i<10; ++i)
            result += start[i] * temp[9][i];
       result %= MOD;
       cout << result << endl;
       }
       else if (N == 1) cout << 4 << endl;
       else cout << 0 << endl;
    }
    return 0;
}
