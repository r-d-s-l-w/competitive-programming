/*
ID: radek.m1
TASK: palsquare
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
using vc = vector<char>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;

constexpr ll MOD = 1000000007;
constexpr ll INI = -1;
constexpr ll IN = 5000 + 10;
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

char xd(int x){
    switch(x)
    {
    case 10: return 'A'; break;
    case 11: return 'B'; break;
    case 12: return 'C'; break;
    case 13: return 'D'; break;
    case 14: return 'E'; break;
    case 15: return 'F'; break;
    case 16: return 'G'; break;
    case 17: return 'H'; break;
    case 18: return 'I'; break;
    case 19: return 'J'; break;
    }
}

string int_to_string(int x, int base){
    string res = "";
    while (x!=0){
        x%base>9?res+=xd(x%base):res+=(x%base+48);
        x/=base;
    }
    reverse(ALL(res));
    return res;
}

bool is_palindrome(int x, int base){
    string s = int_to_string(x*x, base);
    return equal(ALL(s),s.rbegin());
}

int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    freopen("palsquare.in","r",stdin); freopen("palsquare.out","w",stdout);
    cin >> n;
    for (int i=1; i<=300; ++i)
        if (is_palindrome(i,n))
            cout << int_to_string(i,n) << ' ' << int_to_string(i*i,n) << endl;
    return 0;
}
