/// Radoslaw Mysliwiec 2019
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
 
constexpr int INI = -1;
constexpr ll INF = 1e18 + 1;
constexpr int IN = 1e6 + 10;
constexpr int MOD = 1e9 + 7;
constexpr ld EPS = 1e-9;
 
struct P{
    int x;
    int y;
};
 
ll n, z;
P tab[210];
ll dp[210][210];
pi przek[210][210][2];
 
ll przekatna(P a, P b){
    return abs(a.x-b.x)*abs(a.x-b.x)+abs(b.y-a.y)*abs(b.y-a.y);
}
 
void call_ans(int i, int j){
    for (int k=0; k<2; ++k)
    if (przek[i][j][k].F != przek[i][j][k].S){
        cout << przek[i][j][k].F << ' ' << przek[i][j][k].S << ' ';
        call_ans(przek[i][j][k].F,przek[i][j][k].S);
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    cin >> z;
    while(z--){
        cin >> n;
        for(int i=0; i<n; ++i){
            cin >> tab[i].x >> tab[i].y;
        }
        for(int i=2; i<n-1; ++i){
            for (int j=0; j<n; ++j){
                ll best = INF;
                for (int k=j+1; k<j+i; ++k){
                    ll temp = 0;
                    // punkt 1 znajduje sie w k%n, drugi w j, trzeci w (i+j)%n
                    // przekatne sa odpowiednie (j,k%n) i (k%n,(i+j)%n)
                    if (abs(j-k) > 1)
                        temp += dp[k-j][j];
 
                    if (abs(k-(i+j)) > 1)
                        temp += dp[i+j-k][k%n];
 
                    if (temp < best){
                        best = temp;
 
                        if (abs(j-k) > 1)
                            przek[j][(i+j)%n][0] = {j,k%n};
                        else przek[j][(i+j)%n][0] = {0,0};
 
                        if (abs(k-(i+j)) > 1)
                            przek[j][(i+j)%n][1] = {k%n,(i+j)%n};
                        else przek[j][(i+j)%n][1] ={0,0};
 
                    }
                    //if (j==0 && i==3) cout << "          " << temp << endl;
                }
                dp[i][j] = best + przekatna(tab[j],tab[(j+i)%n]);
            }
        }
 
        pll res = {INF,0};
 
        for(int i=0; i<n; ++i)
        if (res.F > dp[n-2][i]){
            res.F = dp[n-2][i];
            res.S = i;
        }
 
        if (res.F == 0) cout << 0 << endl;
        else {
            cout << dp[n-2][res.S] << ' ' << res.S << ' ' << (res.S+n-2)%n << ' ';
            call_ans(res.S,(res.S+n-2)%n);
            cout << endl;
        }
 
        /*
        cout << endl << endl;
        for(int i=0; i<n; ++i){
            for(int k=0; k<2; ++k){
                for(int j=0; j<n; ++j)
                    cout << przek[i][j][k].F << ' ' << przek[i][j][k].S << " | ";
                cout << endl;
            }
 
        }
 
        cout << endl << endl;
        for (int i=0; i<n; ++i){
        for (int j=2; j<n-1; ++j)
            cout << dp[j][i] << ' ';
            cout << endl;
        }*/
    }
 
 
}
