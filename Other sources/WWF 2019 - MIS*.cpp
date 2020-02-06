// Radoslaw Mysliwiec 2019
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
 
constexpr ll INI = -1;
constexpr ll IN = 1010;
constexpr double INF = 1e9 + 1;
 
ll parent[100100], cost[100100], ability[100100];
ll res, t, n, money;
vll adj[100100];
vll sol;
bool vis[100100];
 
void dfs(int s){
      if (vis[s]) return;
      vis[s] = true;
      sol.PB(cost[s]);
      for (auto u: adj[s])
              dfs(u);
}
 
void ini(){
      for (int i=0; i<=n; ++i)
              vis[i] = 0;
}
 
int main(){
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin >> t;
      while (t--){
              cin >> n >> money; res = 0;
              for (int i=1; i<=n; ++i)
                      adj[i].clear();
              for (int i=1; i<=n; ++i)
                      cin >> parent[i] >> cost[i] >> ability[i];
              for (int i=2; i<=n; ++i)
                      adj[parent[i]].PB(i);
              for (int i=1; i<=n; ++i){
                      ini();
                      sol.clear();
                      dfs(i);
                      sort(ALL(sol));
                      ll temp = money, ctr = 0;
                      for (int j=0; j<sol.size(); ++j){
                              if (temp >= sol[j]) {
                                      temp -= sol[j];
                                      ++ctr;
                              }
                              else break;
                      }
                      ll newres = ctr * ability[i];
                      res = max(res,newres);
              }
              cout << res << endl;
      }
}
