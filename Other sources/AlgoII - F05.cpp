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
 
ll koszt[200100];
int a, b, z, n, root = 1;
vi adj[200100];
ll dp[200100][2];
bool is[200100];
 
void ini(){
    for(int i=0; i<=n; ++i){
        adj[i].clear();
        dp[i][0] = -1;
        dp[i][1] = -1;
        is[i] = 0;
    }
}
 
ll dfs(int V, int pV){
    ll sum0 = 0, sum1 = 0;
    for (auto u: adj[V]){
        if (u == pV) continue;
        dfs(u,V);
        sum0 += min(dp[u][0], dp[u][1]);
        sum1 += dp[u][1];
    }
    dp[V][0] = sum1;
    dp[V][1] = sum0 + koszt[V];
}
 
void find_solution(int V, int pV){
    if ((is[pV] && dp[V][1] < dp[V][0]) || !is[pV])
        is[V] = 1;
 
    for (auto u: adj[V]){
        if (u == pV) continue;
        find_solution(u,V);
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    cin >> z;
    while(z--){
        cin >> n; ini();
        for (int i=1; i<=n; ++i)
            cin >> koszt[i];
        for (int i=1; i<n; ++i){
            cin >> a >> b;
            adj[a].PB(b);
            adj[b].PB(a);
        }
        dfs(1,0);
        if (dp[1][1] < dp[1][0])
            is[1] = 1;
 
        cout << min(dp[1][0],dp[1][1]) << endl;
        for (auto u: adj[1])
            find_solution(u,1);
        for (int i=1; i<=n; ++i)
            cout << is[i]; cout<<endl;
    }
}
