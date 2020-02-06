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
 
char c;
int n, x, res;
bool tab[5210][5210];
 
void xd(int i, int j){
    if (c == '0') {
        tab[i][j] = 0; tab[i][j+1] = 0; tab[i][j+2] = 0; tab[i][j+3] = 0;
    }
    else if (c == '1') {
        tab[i][j] = 0; tab[i][j+1] = 0; tab[i][j+2] = 0; tab[i][j+3] = 1;
    }
    else if (c == '2') {
        tab[i][j] = 0; tab[i][j+1] = 0; tab[i][j+2] = 1; tab[i][j+3] = 0;
    }
    else if (c == '3') {
        tab[i][j] = 0; tab[i][j+1] = 0; tab[i][j+2] = 1; tab[i][j+3] = 1;
    }
    else if (c == '4') {
        tab[i][j] = 0; tab[i][j+1] = 1; tab[i][j+2] = 0; tab[i][j+3] = 0;
    }
    else if (c == '5') {
        tab[i][j] = 0; tab[i][j+1] = 1; tab[i][j+2] = 0; tab[i][j+3] = 1;
    }
    else if (c == '6') {
        tab[i][j] = 0; tab[i][j+1] = 1; tab[i][j+2] = 1; tab[i][j+3] = 0;
    }
    else if (c == '7') {
        tab[i][j] = 0; tab[i][j+1] = 1; tab[i][j+2] = 1; tab[i][j+3] = 1;
    }
    else if (c == '8') {
        tab[i][j] = 1; tab[i][j+1] = 0; tab[i][j+2] = 0; tab[i][j+3] = 0;
    }
    else if (c == '9') {
        tab[i][j] = 1; tab[i][j+1] = 0; tab[i][j+2] = 0; tab[i][j+3] = 1;
    }
    else if (c == 'A') {
        tab[i][j] = 1; tab[i][j+1] = 0; tab[i][j+2] = 1; tab[i][j+3] = 0;
    }
    else if (c == 'B') {
        tab[i][j] = 1; tab[i][j+1] = 0; tab[i][j+2] = 1; tab[i][j+3] = 1;
    }
    else if (c == 'C') {
        tab[i][j] = 1; tab[i][j+1] = 1; tab[i][j+2] = 0; tab[i][j+3] = 0;
    }
    else if (c == 'D') {
        tab[i][j] = 1; tab[i][j+1] = 1; tab[i][j+2] = 0; tab[i][j+3] = 1;
    }
    else if (c == 'E') {
        tab[i][j] = 1; tab[i][j+1] = 1; tab[i][j+2] = 1; tab[i][j+3] = 0;
    }
    else if (c == 'F') {
        tab[i][j] = 1; tab[i][j+1] = 1; tab[i][j+2] = 1; tab[i][j+3] = 1;
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    //freopen("test.in","r",stdin); freopen("test.out","w",stdout);
    cin >> n;
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; j+=4){
            cin >> c;
            xd(i,j);
        }
    }
 
    res = n;
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            int temp = 1;
            while(tab[i][j] == tab[i][j+1] && j<n-1){
                ++temp;
                ++j;
            }
            //cout << temp << endl;
            res = gcd(res,temp);
            if (res == 1) break;
        }
        if (res == 1) break;
    }
 
    for (int j=0; j<n; ++j){
        for (int i=0; i<n; ++i){
            int temp = 1;
            while(tab[i][j] == tab[i+1][j] && i<n-1){
                ++temp;
                ++i;
            }
            //cout << temp << endl;
            res = gcd(res,temp);
            if (res == 1) break;
        }
        if (res == 1) break;
    }
 
    cout << res;
    
    return 0;
}
