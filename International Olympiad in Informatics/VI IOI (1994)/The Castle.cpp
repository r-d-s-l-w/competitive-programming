/*
ID: radek.m1
TASK: castle
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

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll,ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;

constexpr ll MOD = 1;
constexpr ll INI = -1;
constexpr ll IN = 1 + 10;
constexpr ll INF = 1e9 + 1;
constexpr ld EPS = 1e-9;

struct res{
    int res;
    int node;
    char dir;
};

inline ll two(ll n) {return 1<<n;}
inline bool EQ(ld a, ld b) {return fabs(a-b)<EPS;}
inline bool is_set(ll n, ll k) {return (n>>k)&1;}
inline void set_bit(ll &n, ll k) {n|=two(k);}
inline void unset_bit(ll &n, ll k) {n&=~two(k);}
inline ll last_bit(ll n) {return n&(-n);}
inline ll ones(ll n) {ll res=0;while(n&&++res)n-=last_bit(n);return res;}
inline ll gcd(ll a, ll b) {return b==0?a:gcd(b,a%b);}
inline ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

int n,m,in,nodes,xd,max_sz;
res max_sz2;
vi adj[3000];
bool visited[3000];
int sz[3000], room[3000];

void add_edge(int val, int x, int y){
    if (!is_set(val,0)) {adj[n*y+x].PB(n*y+x-1); adj[n*y+x-1].PB(n*y+x);}
    if (!is_set(val,1)) {adj[n*y+x].PB(n*y+x-n); adj[n*y+x-n].PB(n*y+x);}
    if (!is_set(val,2)) {adj[n*y+x].PB(n*y+x+1); adj[n*y+x+1].PB(n*y+x);}
    if (!is_set(val,3)) {adj[n*y+x].PB(n*y+x+n); adj[n*y+x+n].PB(n*y+x);}
}

void dfs(int s){
    if (visited[s]) return;
    visited[s] = true;
    ++nodes;
    for(auto u: adj[s])
        dfs(u);
}

void set_size(int s, int x, int y){
    if (sz[s]) return;
    sz[s] = x;
    room[s] = y;
    for (auto u: adj[s])
        set_size(u, x, y);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    freopen("castle.in","r",stdin); freopen("castle.out","w",stdout);
    cin >> n >> m;
    for (int i=0; i<m; ++i)
    for (int j=1; j<=n; ++j){
        cin >> in;
        add_edge(in,j,i);
    }
    for (int i=0; i<m; ++i)
    for (int j=1; j<=n; ++j)
        if (!visited[i*n+j]){
            ++xd;
            nodes = 0;
            dfs(i*n+j);
            set_size(i*n+j, nodes, xd);
        }
    for (int i=1; i<=m*n; ++i)
        max_sz = max(max_sz, sz[i]);

    for (int i=1; i<=n; ++i)
    for (int j=m-1; j>=0; --j){
        if (j != 0){
            if (room[i+j*n] != room[i+j*n-n])
            if (max_sz2.res < sz[i+j*n] + sz[i+j*n-n]){
                max_sz2.res = sz[i+j*n] + sz[i+j*n-n];
                max_sz2.node = i+j*n;
                max_sz2.dir = 'N';
            }
        }
        if (i%n != 0){
            if (room[i+j*n] != room[i+j*n+1])
            if (max_sz2.res < sz[i+j*n] + sz[i+j*n+1]){
                max_sz2.res = sz[i+j*n] + sz[i+j*n+1];
                max_sz2.node = i+j*n;
                max_sz2.dir = 'E';
            }
        }
    }

    cout << xd << endl << max_sz << endl << max_sz2.res
    << endl << (max_sz2.node+n-1)/n << ' ' << (max_sz2.node-1)%n + 1 << ' ' << max_sz2.dir << endl;


    return 0;
}
