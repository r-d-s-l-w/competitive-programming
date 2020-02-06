// Radoslaw Mysliwiec 2019
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB emplace_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;
 
ll tab[110], n, k, t;
ll bag;
 
void ini(){
    for (int x=0; x<110; ++x)
        tab[x] = 0;
    bag = 0;
    n = 0;
    k = 0;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> bag >> k;
        for (int x=0; x<n; ++x)
            cin >> tab[x];
        bool xd = true;
 
        for (int i=0; i<n-1; ++i){
            if (tab[i+1] - tab[i] > k + bag){
                xd = false; break;
            }
            else {
                int tmp = tab[i+1] - k;
                bag += tab[i] - max(0,tmp);
            }
        }
        if (xd == false) cout << "NO\n";
        else cout << "YES\n";
    }
 
 
    return 0;
}
