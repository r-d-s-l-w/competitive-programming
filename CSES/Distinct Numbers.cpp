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
 
int n, res;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n;
    vi tab(n);
    int tmp = 0;
    for (int i=0; i<n; ++i)
        cin >> tab[i];
    sort(ALL(tab));
 
    for (int i=0; i<n; ++i){
        if (tab[i] != tmp){
            tmp = tab[i];
            ++res;
        }
    }
    cout << res << endl;
}
