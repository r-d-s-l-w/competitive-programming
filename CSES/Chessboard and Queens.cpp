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
 
bool tab[9][9];
int diag1[20], diag2[20], col[10];
int res;
 
void solve(int stg){
    if (stg == 9){
        ++res;
        return;
    }
    for (int i=1; i<=8; ++i){
        if (!diag1[i + stg] && !diag2[8 - stg + i] && !col[i] && !tab[stg][i]){
            ++diag1[i + stg];
            ++diag2[8 - stg + i];
            ++col[i];
            solve(stg + 1);
            --diag1[i + stg];
            --diag2[8 - stg + i];
            --col[i];
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    for (int i=1; i<=8; ++i){
        for (int j=1; j<=8; ++j){
            char tmp;
            cin >> tmp;
            tmp == '.' ? tab[i][j] = 0 : tab[i][j] = 1;
        }
    }
 
    solve(1);
 
    cout << res << endl;
 
}
