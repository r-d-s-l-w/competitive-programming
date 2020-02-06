/// Radoslaw Mysliwiec 2019
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
 
using namespace std;
 
#define F first
#define S second
#define PB emplace_back
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
 
int n, h , res;
int tab[1010];
vi arr;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    cin >> n >> h;
    for (int i=1; i<=n; ++i){
        cin >> tab[i];
    }
    for (int i=1; i<=n; ++i){
        arr.PB(tab[i]);
        sort(arr.rbegin(),arr.rend());
        int temp = h; bool possible = 1;
        for (int i=0; i<arr.size(); i+=2){
            if (temp < arr[i]) possible = false;
            temp -= arr[i];
        }
        if (possible) res = max(res, i);
        if (!possible) break;
    }
    cout << res << endl;
 
    return 0;
}
