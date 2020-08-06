/*
ID: radek.m1
TASK: namenum
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

string serializeName(const string &in){
    string ret = "";
    for(int i = 0; i < in.length(); ++i){
        if(in[i] == 'Q' || in[i] == 'Z')
             return "1";
        if(in[i] < 'Q')
             ret += ((in[i] - 'A') / 3) + '2';
        else ret += ((in[i] - 'Q') / 3) + '7';
    }
    return ret;
}

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in"), fdict ("dict.txt");

    string serial;
    fin >> serial;

    bool found = false;
    string entry;
    while(fdict >> entry)
    if(entry.length() == serial.length() && serializeName(entry) == serial){
        found = true;
        fout << entry << endl;
    }
    if(!found)
        fout << "NONE" << endl;
    return 0;
}
