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
constexpr ll IN = 100000 + 100;
constexpr ll INF = 1e9 + 1;
constexpr ld EPS = 1e-9;

struct con {
    ll value;
    ll deadline;
    ll time;
};

class conCMP {
public:
    int operator()(const con &a, const con &b){
        return a.value < b.value;
    }
};

bool cmp(con a, con b){
    if (a.deadline == b.deadline) return a.value > b.value;
    return a.deadline < b.deadline;
}

inline ll two(ll n) {return 1<<n;}
inline bool EQ(ld a, ld b) {return fabs(a-b)<EPS;}
inline bool is_set(ll n, ll k) {return (n>>k)&1;}
inline void set_bit(ll &n, ll k) {n|=two(k);}
inline void unset_bit(ll &n, ll k) {n&=~two(k);}
inline ll last_bit(ll n) {return n&(-n);}
inline ll ones(ll n) {ll res=0;while(n&&++res)n-=last_bit(n);return res;}
inline ll gcd(ll a, ll b) {return b==0?a:gcd(b,a%b);}
inline ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

ll T, n, TIME;
ld result;
con x;
con tab[IN];
priority_queue<con,vector<con>,conCMP> heap;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(2);
    ///freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    cin >> T;
    while (T--){
        cin >> n;
        for (int i=0; i<n; ++i)
            cin >> tab[i].value >> tab[i].time >> tab[i].deadline;
        sort(tab, tab+n ,cmp);
        //cout << endl;
        //for (int i=0; i<n; ++i)
            //cout << tab[i].value << ' ' << tab[i].time << ' ' << tab[i].deadline << endl; cout << endl;

        for (int i=0; i<n; ++i){
            heap.push(tab[i]);
            TIME += tab[i].time;
            if (tab[i].deadline < TIME){
                //cout << tab[i].deadline << ' ' << TIME << endl;
                ll diff = TIME - tab[i].deadline;
                TIME -= diff;
                while (diff != 0){
                    //cout << heap.top().time << endl;
                    if (heap.top().time > diff){
                        result += ld(diff) / ld(heap.top().value);
                        x = heap.top(); x.time -= diff;
                        heap.pop();
                        heap.push(x);
                        diff = 0;
                    }
                    else {
                        result += ld(heap.top().time) / ld(heap.top().value);
                        diff -= heap.top().time;
                        heap.pop();
                    }
                }
            }
        }
        cout << result << endl;
        heap = priority_queue<con,vector<con>,conCMP>();
        TIME = 0;
        result = 0;
    }

}
