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
 
int n, m;
bool arr[550][550];
bool arr2[550][550];
int tab[550];
int tab2[550];
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
        cin >> arr[i][j];
    for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
        cin >> arr2[i][j];
    for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
        if (!arr2[i][j]) arr[i][j] = !arr[i][j];
 
    for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
        if(!arr[i][j]) ++tab[i];
 
    for (int j=0; j<m; ++j)
    for (int i=0; i<n; ++i)
        if (!arr[i][j]) ++tab2[j];
 
    bool poss = 1;
    //cout << endl;
 
   // for (int i=0; i<n; ++i){
    //    for (int j=0; j<m; ++j) cout << arr[i][j]<< ' '; cout<< endl;
    //}
 
 
   // cout << endl;
    for (int i=0; i<n; ++i)
        if (tab[i]%2) poss = 0;
    for (int i=0; i<m; ++i)
        if (tab2[i]%2) poss = 0;
 
    if (poss) cout << "Yes\n";
    else cout << "No\n";
 
 
 
    return 0;
}
