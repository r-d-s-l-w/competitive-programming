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
 
int res = 0;
int tab[110];
bool poss = 1;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> tab[i];
    }
 
    for (int i=0; i<n-1; ++i){
        if (tab[i] == 2 && tab[i+1] == 3) poss = 0;
        else if (tab[i] == 3 && tab[i+1] == 2) poss = 0;
        else {
            if (tab[i] == 1 && tab[i+1] == 3) res += 4;
            else if (tab[i] == 3 && tab[i+1] == 1) res += 4;
 
            else if (tab[i] == 2 && tab[i+1] == 1 && i > 0 && tab[i-1] == 3) res += 2;
            else if (tab[i] == 1 && tab[i+1] == 2 && i > 0 && tab[i-1] == 3) res += 2;
 
            else if (tab[i] == 2 && tab[i+1] == 1) res += 3;
            else if (tab[i] == 1 && tab[i+1] == 2) res += 3;
        }
    }
    if (poss) cout << "Finite\n" << res << endl;
    else cout << "Infinite\n";
 
    return 0;
}
