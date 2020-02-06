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
constexpr ll IN = 10e5 + 1;
constexpr ll iNF = 1e9 + 1;
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

ll T, x;
priority_queue<ll> a;
priority_queue<ll, vll, greater<ll>> b;

void result(){
    if (a.size() == b.size() && b.top() < a.top()){
        cout << b.top() << endl;
        b.pop();
    }
    else{
        cout << a.top() << endl;
        a.pop();
        if (a.size()<b.size()){
            a.push(b.top());
            b.pop();
        }
    }
}

void add(){
    if (a.empty()) a.push(x);
    else if (a.size() == b.size()){
        if (x <= b.top()) a.push(x);
        else {
            a.push(b.top());
            b.pop();
            b.push(x);
        }
    }
    else if (a.size() > b.size()){
        if (x >= a.top()) b.push(x);
        else {
            b.push(a.top());
            a.pop();
            a.push(x);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    ///freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    cin >> T;
    while (T--){
        while(cin >> x){
            if (x == 0) break;
            else if (x == -1) result();
            else add();
            //if (!a.empty() && !b.empty())cout << "    " << a.top() << ' ' << b.top() << endl;
        }
        a = priority_queue<ll>();
        b = priority_queue<ll, vll, greater<ll>>();
    }
}
