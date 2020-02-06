// Radoslaw Mysliwiec 2019
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
 
int z, n, m, a, b, dp[2][500100];
vi adj[2][500100];
 
int dfs(int x, bool stg){
    if (dp[stg][x] != INI) return dp[stg][x]; // pierwsza magiczna linijka
    if (adj[stg][x].size() == 0) return dp[stg][x] = 0; // przypadek bazowy
    int temp = 0;
    for(auto u: adj[stg][x])
        temp = max(temp, dfs(u,stg));
    return dp[stg][x] = temp + 1; // druga magiczna linijka
}
 
void ini(){
    for (int stg=0; stg<2; ++stg)
    for (int i=0; i<=n; ++i){
        dp[stg][i] = -1;
        adj[stg][i].clear();
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> z;
    while(z--){
        cin >> n >> m;
        ini();
        for(int i=0; i<m; ++i){
            cin >> a >> b;
            adj[0][a].PB(b);
            adj[1][b].PB(a);
        }
        for(int i=1; i<=n; ++i){
            dfs(i,0); dfs(i,1);
            cout << dp[0][i] + dp[1][i] + 1 << ' ';
        } cout << endl;
    }
}
