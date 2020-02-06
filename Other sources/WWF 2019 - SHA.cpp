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
constexpr ll INF = 1e9 + 1;
 
int tab[1010][2];
int res[1010];
vi sol;
char moves[510];
int n, m, k, cycle_length;
bool used[1010];
int it;
 
void prec(int x){
      int temp = x;
      for (int i=0; i<m; ++i){
              if (moves[i] == 'L') temp = tab[temp][0];
              else temp = tab[temp][1];
      }
      res[x] = temp;
      //cout << "XD" << endl;
}
 
int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin >> n >> m >> k;
      for (int i=1; i<=n; ++i)
              cin >> tab[i][0] >> tab[i][1];
      cin >> moves;
 
      for (int i=1; i<=n; ++i)
              prec(i);
      sol.PB(1);
      used[1] = true;
  
      do{
              used[sol.back()] = true;
              sol.PB(res[sol.back()]);
      } while (!used[sol.back()]);
    
      for (int i=0; i<sol.size(); ++i)
              if (sol[i] == sol.back()) {
                      cycle_length = sol.size() - i - 1;
                      it = i;
                      break;
              }
 
      if (k < sol.size() - 1) cout << sol[k] << endl;
      else {
              k -= it;
              k %= cycle_length;
              cout << sol[it + k] << endl;
 
      }
}
