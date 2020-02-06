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
 
string s;
int r, c;
bool tab[5][5];
 
void case0(){
    if (tab[1][1] && tab[1][2] && tab[1][3] && tab[1][4]){
        tab[1][1] = 0; tab[1][2] = 0; tab[1][3] = 0; tab[1][4] = 0;
    }
    if (tab[1][1] == 0){
        tab[1][1] = 1;
        cout << 1 << ' ' << 1 << endl;
    }
    else if (tab[1][2] == 0){
        tab[1][2] = 1;
        cout << 1 << ' ' << 2 << endl;
    }
    else if (tab[1][3] == 0){
        tab[1][3] = 1;
        cout << 1 << ' ' << 3 << endl;
    }
    else if (tab[1][4] == 0){
        tab[1][4] = 1;
        cout << 1 << ' ' << 4 << endl;
    }
}
 
void case1(){
    if (tab[3][1] == 1 && tab[3][3] == 1){
        tab[3][1] = 0; tab[3][3] = 0;
    }
 
    if (tab[3][1] == 0){
        cout << 3 << ' ' << 1 << endl;
        tab[3][1] = 1;
    }
    else if (tab[3][3] == 0){
        cout << 3 << ' ' << 3 << endl;
        tab[3][3] = 1;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    //freopen("test.in","r",stdin); freopen("test.out","w",stdout);
    cin >> s;
    for (int i=0; i<s.length(); ++i){
        if (s[i] == '0') case0();
        else if(s[i] == '1') case1();
    }

    return 0;
}
