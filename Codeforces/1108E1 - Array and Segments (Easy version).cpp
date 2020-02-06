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
 
int n,m,a[350];
pi seg[350];
int res;
vi used_seg;
vi temporary;
vi final_vec;
int final_res;
 
bool good(int i, int maks, int mini){
    if (seg[i].F > maks || seg[i].S < maks)
        if (seg[i].F <= mini && seg[i].S >= mini)
            return 1;
    return 0;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    //freopen("test.in","r",stdin); freopen("test.out","w",stdout);
    cin >> n >> m;
    for(int i=1; i<=n; ++i)
        cin >> a[i];
    for(int i=1; i<=m; ++i)
        cin >> seg[i].F >> seg[i].S;
 
    for (int i=1; i<=n; ++i)
    for (int j=1; j<=n; ++j){
        // inicjuje
        res = 0;
        temporary.clear();
        // kiedy i jest maks j jest min
        if (i != j){
            for (int k=1; k<=m; ++k){
                if (good(k,i,j)){
                    ++res;
                    temporary.PB(k);
                }
            }
            if (final_res < a[i] - a[j] + res){
                //cout << a[i] << ' ' << a[j] << ' ' << res << endl;
                final_res = a[i] - a[j] + res;
                final_vec.clear();
                for (int k = 0; k<temporary.size(); ++k){
                    final_vec.PB(temporary[k]);
                }
            }
        }
    }
 
    cout << final_res << endl << final_vec.size() << endl;
    for (int i=0; i<final_vec.size(); ++i)
        cout << final_vec[i] << ' ';
 
    return 0;
}
