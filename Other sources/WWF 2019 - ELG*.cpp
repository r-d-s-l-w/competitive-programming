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
 
int z, n, temp, it, res;
int x[100100], y[100100], ile[200100], mate[200100];
vi adj[200100];
pi tab[200100];
bool vis[200100];
 
bool dfs(int x){
      if (vis[x]) return false;
      vis[x] = true;
      for (auto u: adj[x]){
              if (mate[u] == -1 || dfs(mate[u])){
                      mate[x] = u;
                      mate[u] = x;
                      return true;
              }
      }
      return false;
}
 
void ini(){
      for (int i=0; i<=2*n; ++i){
              vis[i] = 0;
              mate[i] = -1;
              adj[i].clear();
      }
      res = 0;
}
 
void init(){
      for (int i=0; i<=it + 10; ++i)
              vis[i] = 0;
}
 
int main(){
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     cout.setf(ios::fixed); cout.precision(4);
      cin >> z;
      while (z--){
              cin >> n;
              ini();
              for (int i=0; i<n; ++i){
                      cin >> x[i] >> y[i];
                      ++x[i]; ++y[i];
                      tab[2*i].F = x[i];
                      tab[2*i].S = i + 1;
                      tab[2*i + 1].F = -y[i];
                      tab[2*i + 1].S = -i;
              }
              sort(tab, tab + 2*n);
              temp = tab[0].F;
              it = 0;
              for (int i=0; i < 2*n; ++i){
                      if (temp != tab[i].F) {
                              temp = tab[i].F;
                              ++it;
                      }
                      if (tab[i].S <= 0)
                              y[-tab[i].S] = it;
                      else if (tab[i].S > 0)
                              x[tab[i].S - 1] = it;
              }
 
              for (int i=0; i<n; ++i){
                      adj[x[i]].PB(y[i]);
                      adj[y[i]].PB(x[i]);
              }
 
              for (int i=0; i<=it; ++i) {
                      if (mate[i] == -1){
                              init();
                              if (dfs(i)) ++res;
                      }
              }
              cout << res << endl;
      }
 
}
