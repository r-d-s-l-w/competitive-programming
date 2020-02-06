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
 
int res;
vector<char> tmp;
string s;
vector<vector<bool>> vis(10, vector<bool>(10, 1));
int I = 1, J = 1, a;
vi A{0,0,1,-1};
vi B{1,-1,0,0};
 
void solve(int stg){
    if (stg == 49){
        ++res;
        return;
    }
    if (I == 7 && J == 1) return;
    if (vis[I+1][J] == 1 && vis[I-1][J] == 1 && vis[I][J-1] == 0 && vis[I][J+1] == 0) return;
    if (vis[I+1][J] == 0 && vis[I-1][J] == 0 && vis[I][J-1] == 1 && vis[I][J+1] == 1) return;
 
    if (s[stg-1] == 'L' || s[stg-1] == '?'){
        if (!vis[I][J-1]){
            --J;
            vis[I][J] = true;
            solve(stg+1);
            vis[I][J] = false;
            ++J;
        }
    }
    if (s[stg-1] == 'R' || s[stg-1] == '?'){
        if (!vis[I][J+1]){
            ++J;
            vis[I][J] = true;
            solve(stg+1);
            vis[I][J] = false;
            --J;
        }
    }
    if (s[stg-1] == 'U' || s[stg-1] == '?'){
        if (!vis[I-1][J]){
            --I;
            vis[I][J] = true;
            solve(stg+1);
            vis[I][J] = false;
            ++I;
        }
    }
    if (s[stg-1] == 'D' || s[stg-1] == '?'){
        if (!vis[I+1][J]){
            ++I;
            vis[I][J] = true;
            solve(stg+1);
            vis[I][J] = false;
            --I;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> s;
 
    for (int i=1; i<=7; ++i)
    for (int j=1; j<=7; ++j)
        vis[i][j] = 0;
    vis[1][1] = 1;
    solve(1);
 
    cout << res << endl;
 
}
