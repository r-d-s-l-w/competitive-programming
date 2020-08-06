/*
ID: radek.m1
TASK: beads
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

ll n;
string s;
ll l_ptr, r_ptr=1, temp, res;
ll last_b[4000], last_r[4000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    freopen("beads.in","r",stdin); freopen("beads.out","w",stdout);
    cin >> n >> s;
    s = ' '+s+s;
    for (int i=1; i<s.length(); ++i){
        if (s[i] == 'r') last_r[i] = i;
        else last_r[i] = last_r[i-1];
        if (s[i] == 'b') last_b[i] = i;
        else last_b[i] = last_b[i-1];
    }
    char curr = 'w';
    while (r_ptr < s.length()){
        if (curr == 'r' && s[r_ptr] == 'b')
            l_ptr = last_b[r_ptr - 1];
        else if (curr == 'b' && s[r_ptr] == 'r')
            l_ptr = last_r[r_ptr - 1];

        if (s[r_ptr] != 'w') curr = s[r_ptr];
        res = max(res,r_ptr - l_ptr);
        ++r_ptr;
    }
    if (res > n) cout << n << endl;
    else cout << res << endl;
    return 0;
}
