/// Radek Mysliwiec 2019
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

struct flight{
    ll start, stop, value;
};

constexpr ll MOD = 1;
constexpr ll INI = -1;
constexpr ll IN = 10000 + 100;
constexpr ll INF = 1e9 + 1;
constexpr ld EPS = 1e-9;

inline ll two(ll n) {return 1<<n;}
inline bool EQ(ld a, ld b) {return fabs(a-b)<EPS;}
inline bool is_set(ll n, ll k) {return (n>>k)&1;}
inline void set_bit(ll &n, ll k) {n|=two(k);}
inline void unset_bit(ll &n, ll k) {n&=~two(k);}
inline ll last_bit(ll n) {return n&(-n);}
inline ll ones(ll n) {ll res=0; while(n&&++res)n-=last_bit(n); return res;}
inline ll gcd(ll a, ll b) {return b==0?a:gcd(b,a%b);}
inline ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

ll T, N;
flight tab[IN];
ll cache[IN];

bool cmp(flight a, flight b){
    return b.start>a.start;
}

ll nextin(ll n){
    ll lo = n + 1;
    ll hi = N;
    while (lo < hi){
        ll mid = lo + (hi-lo)/2;
        if (tab[n].stop < tab[mid].start)
            hi = mid;
        else lo = mid + 1;
    }
    return lo;

}

ll solution(ll n){
    if (n == N) return 0;
    if (cache[n] != 0) return cache[n];
    return cache[n] = max(solution(n+1), solution(nextin(n)) + tab[n].value);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    ///freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    cin >> T;
    while (T--){
        cin >> N;
        for (int i=0; i<N; ++i){
            cin >> tab[i].start >> tab[i].stop >> tab[i].value;
            tab[i].stop += tab[i].start;
        }
        for (int i=0; i<=N; ++i)
            cache[i] = 0;
        tab[N].start = INF; tab[N].stop = INF;
        sort(tab, tab+N, cmp);
        cout << solution(0) << endl;
    }
}
