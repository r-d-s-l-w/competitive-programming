/// Radoslaw Mysliwiec 2020
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;
 
int n;
int res, tmp;
map<int,int> mp;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n;
 
    vi tab(n);
 
    for (int i=0; i<n; ++i){
        cin >> tab[i];
    } tab.PB(tab[n-1]);
 
    int R = 0;
    for (int L=0; L<n; ++L){
        while(mp[tab[R]] == 0) {
            mp[tab[R]] = 1;
            ++R;
        }
        res = max(res, R - L);
        mp[tab[L]] = 0;
    }
 
    cout << res << endl;
 
}
