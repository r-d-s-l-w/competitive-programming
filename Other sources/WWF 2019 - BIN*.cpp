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
constexpr ll IN = 500100;
constexpr ll INF = 1e9 + 1;
 
int kmp(string s){
      int n = s.length();
      int res = 0;
      int P[IN];
      P[1] = 0;
      int t = P[1];
      for (int i = 2; i <= n; ++i) {
              while (t > 0 && s[t + 1] != s[i]) t = P[t];
              if (s[t + 1] == s[i]) ++t;
              P[i] = t;
      }
      for (int i=2; i<=n; ++i)
              res = max(res,P[i]);
      return res;
}
 
int z, n;
string s[IN];
 
void sol1(){
      cout << "TAK" << endl;
      for (int i=0; s[0][i]; ++i)
              s[0][i]=='?' ? cout << '1' : cout << s[0][i];
      cout << endl;
}
 
void sol2(){
      int len0 = s[0].length();
      int len1 = s[1].length();
      int len = min(len0,len1);
      bool good = 0;
      for (int i=0; i<len; ++i){
              if (s[0][i] == '?' && s[1][i] == '?'){
                      s[0][i] = '0'; s[1][i] = '1';
                      good = 1;
              }
              else if (s[0][i] == '?' && s[1][i] != '?'){
                      if (s[1][i] == 0) s[0][i] = 1;
                      else if (s[1][i] == 1) s[0][i] = 0;
                      good = 1;
              }
              else if (s[1][i] == '?' && s[0][i] != '?'){
                      if (s[0][i] == 0) s[1][i] = 1;
                      else if (s[0][i] == 1) s[1][i] = 0;
                      good = 1;
              }
              else if (s[0][i] != s[1][i]) good = 1;
      }
      for (int i=len; i<len0; ++i)
              if (s[0][i] == '?') s[0][i] = '1';
      for (int i=len; i<len1; ++i)
              if (s[1][i] == '?') s[1][i] = '1';
 
      if (good) cout << "TAK" << endl << s[0] << endl << s[1] << endl;
      else cout << "NIE" << endl;
}
 
void sol3(){
      int len0 = s[0].length();
      int len1 = s[1].length();
      int len2 = s[2].length();
      for (int i=48; i<=49; ++i)
      for (int j=48; j<=49; ++j)
      for (int k=48; k<=49; ++k){
              string a, b, c;
              a = s[0];
              b = s[1];
              c = s[2];
              for (int l=0; l<len0; ++l)
                      if (a[l] == '?') a[l] = i;
              for (int l=0; l<len1; ++l)
                      if (b[l] == '?') b[l] = j;
              for (int l=0; l<len2; ++l)
                      if (c[l] == '?') c[l] = k;
 
              if (kmp("&"+a+"$"+b+"#"+c+"*") != a.length() &&
              kmp("&"+b+"$"+a+"#"+c+"*") != b.length() &&
              kmp("&"+c+"$"+a+"#"+b+"*") != c.length() ) {
                      cout << "TAK" << endl;
                      cout << a << endl << b << endl << c << endl;
                      return;
              }
      }
      cout << "NIE" << endl;
}
 
void sol4(){
      bool good = 1;
      for (int i=0; i<n; ++i){
              for (int j=0; j<n; ++j)
                      if (j != i && kmp("&"+s[i]+"#"+s[j]+"$") == s[i].length()){
                              good = 0;
                              break;
                      }
      }
 
      if (good) {
              cout << "TAK" << endl;
              for (int i=0; i<n; ++i)
                      cout << s[i] << endl;
      }
      else cout << "NIE" << endl;
}
 
int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cout.setf(ios::fixed); cout.precision(1);
      //freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
      cin >> z;
      while (z--){
              cin >> n;
              for (int i=0; i<n; ++i)
                      cin >> s[i];
              if (n == 1) sol1();
              else if (n == 2) sol2();
              else if (n == 3) sol3();
              else sol4();
 
              for (int i=0; i<n; ++i)
                      s[i].clear();
      }
}
