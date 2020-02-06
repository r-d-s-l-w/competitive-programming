#include <bits/stdc++.h>
#pragma GCC optimize("O3")
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
 
using ll = long long;
using ld = long double;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;
 
constexpr int MOD = 1;
constexpr int INPUT = 1e5 + 100;
constexpr int INF = 1e9 + 1;
constexpr double EPS = 1e-9;
 
ll tab[INPUT];
vi arr;
int l;
 
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.setf(ios::fixed); cout.precision(20);
    //freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    cin >> l;
    ll maks = 0, mini = INF;
    for (int i=0; i<l; ++i){
        cin >> tab[i];
        mini = min(mini, tab[i]);
        maks = max(maks, tab[i]);
    }
    sort(tab,tab+l);
    int x = min(tab[l-1]-tab[1], tab[l-2]-tab[0]);
    cout << x;
}
