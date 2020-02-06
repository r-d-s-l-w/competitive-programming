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

ll T, l_ptr, r_ptr, res_1, res_2;

matrix mul(matrix a, matrix b){
    matrix C(4, vll(4));
    REP(i,3) REP(j,3) REP(k,3)
        C[i][j] = (C[i][j] + a[i][k] * b[k][j]) % MOD;
    return C;
}

matrix pow(matrix a, int n){
    if (n == 1) return a;
    if (n % 2) return mul(a, pow(a,n-1));
    matrix X = pow(a,n/2);
    return mul(X,X);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    ///freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    matrix rec = {{0,0,0,0},{0,0,1,0},{0,1,1,0},{0,1,0,1}};
    vll F = {0,0,1,0};
    cin >> T;
    while (T--){
        res_1 = res_2 = 0;
        cin >> l_ptr >> r_ptr;
        if (l_ptr >= 2){
            matrix temp_1 = pow(rec,l_ptr);
            REP(i,3) res_1 += F[i] * temp_1[3][i];
        }
        if (r_ptr >= 2){
            matrix temp_2 = pow(rec,r_ptr+1);
            REP(i,3) res_2 += F[i] * temp_2[3][i];
        }
        ll res = (res_2 % MOD) - (res_1 % MOD);
        if (res < 0) cout << MOD + res << endl;
        else cout << res << endl;
    }
    return 0;
}
