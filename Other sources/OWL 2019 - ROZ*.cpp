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
 
int n,m,a,b;
bool matrix[10000][10000];
 
ll sol(){
    ll res = 0;
    for (int i=1; i<=n; ++i)
    for (int j=1; j<=n; ++j)
    for (int k=1; k<=n; ++k){
        if (i != j && j != k && k != i){
            if ((matrix[i][j] == 1 && matrix[j][k] == 1 && matrix[k][i] == 1) ||
                (matrix[i][j] == 0 && matrix[j][k] == 0 && matrix[k][i] == 0))
                ++res;
        }
    }
    return res/6;
}
 
void ini(){
    for (int i=0; i<=n; ++i)
    for (int j=0; j<=n; ++j)
        matrix[i][j] = 0;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        cin >> n >> m;
        ini();
        for (int i=0; i<m; ++i){
            cin >> a >> b;
            matrix[a][b] = 1;
            matrix[b][a] = 1;
        }
        cout << sol() << endl;
    }
 
    return 0;
}
