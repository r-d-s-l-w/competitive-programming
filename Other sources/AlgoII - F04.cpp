/// Radoslaw Mysliwiec 2019
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB emplace_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;
 
constexpr int INI = -1;
constexpr int INF = 1e9 + 1;
constexpr int IN = 1e6 + 10;
constexpr int MOD = 1e9 + 7;
constexpr ld EPS = 1e-9;
 
vi adj[100100];
bool tab[100100];
int n, x, a, z;
 
void ini(){
    for(int i=0; i<=n; ++i){
        adj[i].clear();
        tab[i] = 0;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    cin >> z;
    while(z--){
        cin >> n;
        ini();
        for(int i=0; i<n; ++i){
            cin >> x;
            for (int j=0; j<x; ++j){
                cin >> a;
                adj[i].PB(a);
            }
        }
        for (int i=n-2; i>=0; --i){
            bool win = 0;
            for (auto u: adj[i])
                if (tab[u] == 0) win = 1;
            tab[i] = win;
        }
 
        for (int i=0; i<n; ++i)
            tab[i]==0?cout<<'P':cout<<'W';
        cout << endl;
    }
}
