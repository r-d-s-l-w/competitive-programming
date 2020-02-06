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

int n;
pll tab[200100]; ll tab2[200100]; int counting[200100];
int counter[100];
vll wynik;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    //freopen("test.in","r",stdin); freopen("test.out","w",stdout);

    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> tab[i].F;
        tab[i].S = i;
        tab2[i] = tab[i].F;
        counting[i] = 1;
    }

    for(int i=0; i<n; ++i){
        while((tab[i].F&1) == 0){
            ++counting[i];
            tab[i].F>>=1;
        }
        ++counter[counting[i]];
    }
    pi res = {0,0};
    for (int i=0; i<90; ++i){
        if (counter[i] > res.F){
            res.F = counter[i];
            res.S = i;
        }
    }

    for (int i=0; i<n; ++i){
        if (counting[i] != res.S)
            wynik.PB(tab2[i]);
    }

    cout << wynik.size() << endl;
    for (auto x: wynik) cout << x << ' ';
    return 0;
}
