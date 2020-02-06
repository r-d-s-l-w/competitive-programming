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
 
int z, n, b, lewa, L, prawa, R, pierwszy_przed_ferdynandem, pierwszy_po_ferdynandzie;
pi siano[100100];
 
bool wyrwie_sie(){
      int i = pierwszy_przed_ferdynandem, j = pierwszy_po_ferdynandzie;
      while (i >= 0 && j < n){
              if (siano[i].S < siano[j].F - siano[i].F) --i;
              else if (siano[j].S < siano[j].F - siano[i].F)  ++j;
              else return false;
      }
      return true;
}
 
bool przejdzie(int x){
      if (pierwszy_przed_ferdynandem == -1 || pierwszy_po_ferdynandzie == -1) return true;
      for (int i=0; i<n; ++i){
              siano[i].S += x;
              //cout << " " << wyrwie_sie() << ' ' << i << endl;
              if (!wyrwie_sie()) {
                      siano[i].S -= x;
                      return false;
              }
              siano[i].S -= x;
      }
      return true;
      /*
      siano[lewa].S += x;
      int i = pierwszy_przed_ferdynandem, j = pierwszy_po_ferdynandzie;
      while (i >= 0 && j < n){
              if (siano[i].S <= siano[j].F - siano[i].F) --i;
              else if (siano[j].S <= siano[j].F - siano[i].F) ++j;
              else {
                      siano[lewa].S -= x;
                      return false;
              }
              //cout << "    " << i << ' ' << j << endl;
      }
      siano[lewa].S -= x;
      siano[prawa].S += x;
      i = pierwszy_przed_ferdynandem, j = pierwszy_po_ferdynandzie;
      while (i >= 0 && j < n){
              if (siano[i].S <= siano[j].F - siano[i].F) --i;
              else if (siano[j].S <= siano[j].F - siano[i].F) ++j;
              else {
                      siano[prawa].S -= x;
                      return false;
              }
      }
      siano[prawa].S -= x;
      return true;*/
}
 
int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin >> z;
      while (z--){
              cin >> n >> b;
              for (int i = 0; i<n; ++i)
                      cin >> siano[i].S >> siano[i].F;
              sort(siano, siano+n);
              L = R = -INF;
              pierwszy_przed_ferdynandem = -1;
              pierwszy_po_ferdynandzie = -1;
              for (int i=0; i<n; ++i){
                      if (siano[i].F > b){
                              if (siano[i].S - siano[i].F > R){
                                      R = siano[i].S - siano[i].F;
                                      prawa = i;
                              }
                              if (pierwszy_po_ferdynandzie == -1)
                                      pierwszy_po_ferdynandzie = i;
                      }
                      else {
                              if (siano[i].S + siano[i].F > L){
                                      L = siano[i].S + siano[i].F;
                                      lewa = i;
                              }
                              pierwszy_przed_ferdynandem = i;
                      }
              }
              //for (int i=0; i<n; ++i)
                      //cout << ' ' << siano[i].F << ' ' << siano[i].S << endl;
              //cout << pierwszy_przed_ferdynandem << ' ' << pierwszy_po_ferdynandzie << endl;
              //cout << ' ' << lewa << ' ' << prawa << endl;
 
              int l = 0, r = 1e9 + 10;
              // cout << " " << przejdzie(4) << endl;
              while (l < r){
                      int mid = (l + r) / 2;
                      if (przejdzie(mid)) l = mid + 1;
                      else r = mid;
              }
              if (l == 1e9 + 10) cout << -1 << endl;
              else cout << l << endl;
      }
 
 
}
