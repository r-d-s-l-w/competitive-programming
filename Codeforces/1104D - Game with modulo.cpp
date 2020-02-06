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
 
string ans;
char c;
ll a, b;
ll two[32];
 
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    //freopen("test.in","r",stdin); freopen("test.out","w",stdout);
    two[1] = 1;
    for (int i=2; i<32; ++i){
        two[i] = 2*two[i-1];
    }
    int xdd = 0;
    cin >> ans;
    while (ans != "end"){
        for (int i=0; i<32; ++i){
            cout << "? " << two[i] << ' ' << two[i+1] << endl;
            cin >> c;
            if (c == 'x') {
                a = two[i]+1;
                b = two[i+1];
                break;
            }
        }
        while (a<b){
            ll mid = (a + b) / 2;
            cout << "? " << mid << ' ' << b << endl;
            cin >> c;
            if (c == 'x') a = mid + 1;
            else b = mid;
        }
        cout << "! " << a << endl;
        cin >> ans;
    }
    return 0;
}
