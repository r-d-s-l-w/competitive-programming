#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
#define DEBUG(x) cout << '>' << #x << ": " << endl;

using ll = long long;
using ld = long double;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;

constexpr ll MOD = 1;
constexpr ll IN = 6100 + 10;
constexpr ll INI = -1;
constexpr ll INF = 1e9 + 1;
constexpr ld EPS = 1e-9;

inline ll two(ll n) {return 1<<n;}
inline bool is_set(ll n, ll k) {return (n<<k)&1;}
inline bool EQ(ld a, ld b) {return fabs(a-b)<EPS;}
inline void set_bit(ll &n, ll k) {n|=two(k);}
inline void unset_bit(ll &n, ll k) {n&=~two(k);}
inline ll last_bit(ll n) {return n&(-n);}
inline ll ones(ll n) {ll res=0;while(n&&++res)n-=last_bit(n); return res;}
inline ll gcd(ll a, ll b) {return b==0?a:gcd(b,a%b);}
inline ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

string s;
string a, b;
int CD[IN][IN];

ll count_dist(ll i, ll j){
    if (CD[i][j] != INI) return CD[i][j];
    if (i+j > a.length()) return CD[i][j] = 0;
    if (a[i] == b[j]) return CD[i][j] = count_dist(i+1,j+1);
    return CD[i][j] = min(count_dist(i+1,j),count_dist(i,j+1)) + 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //cout.setf(ios::fixed); cout.precision(20);
    //freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    int T;
    cin >> T;
    while (T--){
        cin >> s;
        a = s;
        b = s;
        reverse(ALL(b));
        for (int i=0; i<=b.length(); ++i)
        for (int j=0; j<=b.length(); ++j)
            CD[i][j] = INI;
        cout << count_dist(0,0) << endl;
    }


}
