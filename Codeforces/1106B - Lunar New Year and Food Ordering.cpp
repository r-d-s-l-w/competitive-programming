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
 
ll n, m, x, a, b;
ll dish[IN], price[IN], used[IN];
pll cost[IN];
priority_queue<int, vector<pll>, greater<pll> > pq;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    //freopen("test.in","r",stdin); freopen("test.out","w",stdout);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> dish[i];
    for (int i=0; i<n; ++i){
        cin >> price[i];
        pq.push(MP(price[i],i));
    }
    for (int i=0; i<m; ++i){
        int res = 0;
        cin >> a >> b;
        a-=1;
        if (dish[a] - used[a] >= b){
            used[a] += b; // wszystko mozna
            res = price[a] * b;
        }
        else { // nie wszystko mozna
            res = (dish[a] - used[a]) * price[a];
            b -= (dish[a] - used[a]);
            used[a] = dish[a]; //
 
            while (b != 0 && !pq.empty()){
                if (dish[pq.top().S] - used[pq.top().S] >= b){
                    res += b * pq.top().F;
                    used[pq.top().S] += b;
                    b = 0;
                }
                else if (dish[pq.top().S] != used[pq.top().S]){
                    res += pq.top().F * (dish[pq.top().S] - used[pq.top().S]);
                    b -= dish[pq.top().S] - used[pq.top().S];
                    used[pq.top().S] = dish[pq.top().S];
                }
                if (dish[pq.top().S] == used[pq.top().S]) pq.pop();
            }
 
            if (pq.empty() && b != 0) res = 0;
        }
        cout << res << endl;
    }

    return 0;
}
