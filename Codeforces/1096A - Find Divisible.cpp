/// Radek Mysliwiec 2018
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
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
 
constexpr ll MOD = 1;
constexpr ll IN = 1 + 100;
constexpr ll INF = 1e9 + 1;
constexpr ld EPS = 1e-9;
 
inline ll two(ll n) {return 1<<n;}
inline bool EQ(ld a, ld b) {return fabs(a-b)<EPS;}
inline bool if_set(ll n, ll k) {return (n>>k)&1;}
inline void set_bit(ll &n, ll k) {n|=two(k);}
inline void unset_bit(ll &n, ll k) {n&=~two(k);}
inline ll last_bit(ll n) {return n&(-n);}
inline ll ones(ll n) {ll res=0; while(n&&++res)n-=last_bit(n); return res;}
inline ll gcd(ll a, ll b) {return b==0?a:gcd(b,a%b);}
inline ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}
 
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin.setf(ios::fixed); cin.precision(20);
    //freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    int l, r, t;
    cin >> t;
    while (t--){
        cin >> l >> r;
        cout << l << ' ' << 2*l << endl;
    }
///================================================================
 
 
 
 
 
 
 
 
}
