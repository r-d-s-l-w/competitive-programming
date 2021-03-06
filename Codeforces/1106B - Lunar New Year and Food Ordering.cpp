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
constexpr ll IN = 100000 + 10;
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
 
ll n, m, a, b, k;
ll ilosc[IN], koszt[IN];
pll dania[IN];
 
ll solve(int numer, int ile){
    ll res = 0;
    if (ilosc[numer] >= ile){
        ilosc[numer] -= ile;
        res += ile * koszt[numer];
        ile = 0;
    }
    else {
        res += ilosc[numer] * koszt[numer];
        ile -= ilosc[numer];
        ilosc[numer] = 0;
        while (ile != 0 && k < n){
            if (ilosc[dania[k].S] >= ile){
                ilosc[dania[k].S] -= ile;
                res += ile * koszt[dania[k].S];
                ile = 0;
            }
            else if (ilosc[dania[k].S] != 0) {
                res += ilosc[dania[k].S] * koszt[dania[k].S];
                ile -= ilosc[dania[k].S];
                ilosc[dania[k].S] = 0;
            }
            if (ilosc[dania[k].S] == 0) ++k;
        }
        if (ile != 0 && k>=n) res = 0;
    }
    return res;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    //freopen("test.in","r",stdin); freopen("test.out","w",stdout);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> ilosc[i];
    for (int i=0; i<n; ++i){
        cin >> koszt[i];
        dania[i].F = koszt[i];
        dania[i].S = i;
    }
    sort(dania,dania+n);
    for (int i=0; i<m; ++i){
        cin >> a >> b;
        a -= 1;
        cout << solve(a,b) << endl;
    }
    return 0;
}
