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
 
constexpr int MOD = 1;
constexpr int IN = 2000 + 10;
constexpr int INF = 1e9 + 1;
constexpr ld EPS = 1e-9;
 
int n;
int tab[100100];
int res = 1, temp = 1;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> tab[i];
    for (int i=1; i<n; ++i){
        if (tab[i] >= tab[i-1]) ++temp;
        else temp = 1;
        res = max(res,temp);
    }
    cout << res << endl;
    return 0;
}
