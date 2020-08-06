/*
ID: radek.m1
TASK: pprime
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

vector<string> pal;
vll res;
ll a, b;

void gen_pal(string x){
    if (x.length() <= 8){
       pal.PB(x);
        gen_pal("0" + x + "0");
        gen_pal("1" + x + "1");
        gen_pal("2" + x + "2");
        gen_pal("3" + x + "3");
        gen_pal("4" + x + "4");
        gen_pal("5" + x + "5");
        gen_pal("6" + x + "6");
        gen_pal("7" + x + "7");
        gen_pal("8" + x + "8");
        gen_pal("9" + x + "9");
    }
}

bool is_prime(ll x){
    for (int i=2; i*i<=x; ++i)
        if (x%i == 0) return 0;
    return 1;
}

ll string_to_int(string s){
    ll temp = 1, wynik=0;
    for(int i=s.length()-1; i>=0; --i){
        wynik += temp*(s[i]-48);
        temp *= 10;
    }
    return wynik;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    freopen("pprime.in","r",stdin); freopen("pprime.out","w",stdout);
    cin >> a >> b;
    string k = "";
    gen_pal(k);
    for(int i='0'; i<='9'; ++i){
        string s(1,i);
        gen_pal(s);
    }
    for (int i=0; i<pal.size(); ++i){
        if (pal[i][0] != '0'){
            ll x = string_to_int(pal[i]);
            if (x >= a && x <= b)
                if(is_prime(x)) res.PB(x);
        }
    }
    sort(ALL(res));
    for(int i=0; i<res.size(); ++i)
        cout << res[i] << endl;
    return 0;
}
