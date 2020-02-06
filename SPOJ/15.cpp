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

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;

constexpr ll MOD = 1;
constexpr ll INI = -1;
constexpr ll IN = 10000 + 10;
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

vector<pi> adj[IN];
map<string,int> cities;
ll T, n, m, a, b, r, x, y;
string s, t;
int dist[IN];
bool vis[IN];

int dijkstra(int start, int stop){
    priority_queue<pi> pq;
    dist[start] = 0;
    pq.push(MP(0,start));
    while(!pq.empty()){
        int A = pq.top().S; pq.pop();
        if (vis[A]) continue;
        vis[A] = true;
        for (auto u : adj[A]){
            int B = u.F, W = u.S;
            if (dist[A] + W < dist[B]){
                dist[B] = dist[A] + W;
                pq.push(MP(-dist[B],B));
            }
        }
        if (A == stop) return dist[A];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    ///freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    cin >> T;
    while (T--){
        cin >> n;
        for (int i=1; i<=n; ++i){
            cin >> s;
            cities.insert(MP(s,i));
            cin >> m;
            while(m--){
                cin >> a >> b;
                adj[i].PB(MP(a,b));
            }
        }
        cin >> r;
        while (r--){
            cin >> s >> t;
            x = cities[s]; y = cities[t];
            for(int i=0; i<IN; i++) {dist[i] = INF; vis[i] = false; }
            cout << dijkstra(x, y) << endl;
        }
        cities.clear();
        for (int i=1; i<=n; ++i) adj[i].clear();
    }
}
