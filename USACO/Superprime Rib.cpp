/*
ID: radek.m1
TASK: sprime
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

int ten[10], n;
vi res;

bool prime(int n){
    for (int i=2; i*i<=n; ++i)
        if (n%i==0) return 0;
    return 1;
}

void sprime(int x, int sz){
    if (sz == n) {if (prime(x)) res.PB(x);}
    else if (prime(x)) {
        for (int i=1; i<10; ++i)
            sprime(x*10+i,sz+1);
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    //freopen("sprime.in","r",stdin); freopen("sprime.out","w",stdout);
    cin >> n;
    int temp = 1;
    for (int i=0; i<10; ++i){
        ten[i] = temp;
        temp *= 10;
    }
    for (int i=2; i<10; ++i)
        sprime(i, 1);
    sort(ALL(res));
    for (int i=0; i<res.size(); ++i)
        cout << res[i] << endl;

    return 0;
}
