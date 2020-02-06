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
constexpr ll IN = 410;
constexpr ll INF = 1e9 + 1;
 
struct Point {
      int x, y;
} pivot;
 
class Ziemniak {
      vector <Point> p;
      static int cross(const Point &p0, const Point &p1, const Point &p2) {
              return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
      }
      static int dissqr(const Point &p1, const Point &p2) {
              return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
      }
      static int cmp(const Point &p1, const Point &p2) {
              int c = cross(pivot, p1, p2);
              return c < 0 || (c == 0 && dissqr(pivot, p1) < dissqr(pivot, p2));
      }
      int ans[IN][IN];
public:
      double sol(vi, vi, int);
};
 
double Ziemniak::sol(vi x, vi y, int m) {
      int n = x.size();
      p.resize(n);
      int res = 0;
      for (int i=0; i<n; ++i)
              p[i].x = x[i], p[i].y = y[i];
      for (int i=0; i<n; ++i){
              pivot = p[i];
              vector <Point> hull;
              for (int j=0; j<n; ++j)
                      if (p[i].y < p[j].y || (p[i].y == p[j].y && p[i].x < p[j].x))
                              hull.PB(p[j]);
 
              sort(ALL(hull),cmp);
              memset(ans, 0, sizeof(ans));
              for (int j=1; j<hull.size(); ++j) {
                      for (int k=3; k<=m; ++k) {
                              for (int l=0; l<j; ++l) {
                                      ans[j][k] = max(ans[j][k], ans[l][k - 1] + abs(cross(p[i], hull[j], hull[l])));
                              }
                              if (k <= m) res = max(res, ans[j][k]);
                      }
              }
      }
      return (double)res / 2.;
}
 
int z, n, k;
 
int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cout.setf(ios::fixed); cout.precision(1);
      //freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
      cin >> z;
      while (z--){
              cin >> n >> k;
              vi x(n); vi y(n);
              for (int i=0; i<n; ++i)
                      cin >> x[i] >> y[i];
              Ziemniak *bonifacy = new Ziemniak;
              cout << bonifacy -> sol(x,y,k) << endl;
              x.clear(); y.clear();
              delete bonifacy;
      }
}
