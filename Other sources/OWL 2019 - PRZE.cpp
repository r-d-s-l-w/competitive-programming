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
 
constexpr ll IN = 500100;
 
int n, m, q, a, b, c, d;
int res[32][32][910];
int tab[32][32][910]; // nakrótsza czas z wierzchołka i do
// wierzchołka j przy k-tym poziomie dostępu
 
bool vis[32];
 
 
void floyd(int x){
    for (int i=0; i<=30; ++i)
    for (int j=0; j<=30; ++j)
        res[i][j][x] = tab[i][j][x];
 
    for (int k=0; k<=30; ++k)
    for (int i=0; i<=30; ++i)
    for (int j=0; j<=30; ++j){
        if (res[i][k][x] + res[k][j][x] < res[i][j][x])
            res[i][j][x] = res[i][k][x] + res[k][j][x];
    }
}
 
void ini(){
    for (int i=0; i<32; ++i)
    for (int j=0; j<32; ++j)
    for (int k=0; k<910; ++k)
        tab[i][j][k] = 50000;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ini();
    cin >> n >> m >> q;
    for (int i=0; i<m; ++i){
        cin >> a >> b >> c >> d;
        tab[a][b][d] = min(tab[a][b][d],c);
    }
    for (int i=0; i<32; ++i)
    for (int j=0; j<32; ++j)
    for (int k=1; k<910; ++k)
        tab[i][j][k] = min(tab[i][j][k-1],tab[i][j][k]);
    for (int i=0; i<=900; ++i)
        floyd(i);
    while (q--){
        cin >> a >> b >> c;
        if (res[a][b][900] > c) cout << -1 << endl;
        else {
        int beg = 1, en = 900;
            while (en - beg > 0){
                int mid = (en + beg)/2;
                if (res[a][b][mid] > c)
                    beg = mid + 1;
                else en = mid;
            }
            cout << beg << endl; /*"    ";
           for (int i=1; i<=900; ++i){
                if (res[a][b][i] <= c){
                    cout << i << endl;
                    break;
                }
           }*/
        }
    }
 
    return 0;
}
