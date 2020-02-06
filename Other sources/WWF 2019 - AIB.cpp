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
 
string s;
int n;
int dp[2010][2010];
 
void ini(int sz){
      for (int i=0; i<sz; ++i)
      for (int j=i+1; j<sz; ++j)
              dp[i][j] = -1;
}
 
int sol(int i, int j){
      if (dp[i][j] != -1) return dp[i][j];
      if (s[i] == s[j]) return dp[i][j] = sol(i+1, j-1);
      return dp[i][j] = min(sol(i,j-1), sol(i+1,j)) + 1;
}
 
void solve(int i, int j){
      string a = "";
      while (i < j){
              if (s[i] == s[j]) {
                      a += s[i];
                      ++i; --j;
              }
              else if (dp[i+1][j] < dp[i][j-1]){
                      a += s[i];
                      ++i;
              }
              else if (dp[i+1][j] > dp[i][j-1]){
                      a += s[j];
                      --j;
              }
              else if (s[i] < s[j]){
                      a += s[i];
                      ++i;
              }
              else if (s[i] > s[j]){
                      a += s[j];
                      --j;
              }
      }
      cout << a;
      if (i == j) cout << s[i];
      reverse(ALL(a));
      cout << a << endl;
}
 
 
 
 
 
int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
      cin >> n;
      for (int i=0; i<n; ++i){
              cin >> s;
              int len = s.length();
              ini(len);
              sol(0,len-1);
              solve(0,len-1);
      }
}
