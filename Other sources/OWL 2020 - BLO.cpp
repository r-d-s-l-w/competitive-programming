/// Radoslaw Mysliwiec 2020
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
#define debug if(0)
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
 
constexpr int col = 1005;
constexpr int pion = 4000000;
constexpr int poz = 2000000;
 
void solve(){
    int n, m;
    cin >> n >> m;
    int start= 0, stop = 0;
 
    vector<bool> vis(6000000, 0);
    vector<int> dist(6000000, 0);
    //vector<int> par(6000000, 0);
 
    /// GORA PRAWO DOL LEWO
    vi moves1{pion-col, poz+1, pion+2*col, poz-2}; // dla zwykl
    vi moves2{-col, -poz+2, col, -poz-1}; // dla poz
    vi moves3{-pion-2*col, 1, -pion+col, -1}; // dla pion
 
    vi moves{-col, -2*col, 1, 2, col, 2*col, -1, -2};
    vi movesb{-col, -col+1, 0, 2, col, col+1, 0, -1};
    vi movesc{-2*col, 0, 1, 1-col, col, 0, -1, -1-col};
 
    for (int i=2; i<=n+1; ++i){
        for (int j=2; j<=m+1; ++j){
            char c;
            cin >> c;
            if (c != 'x') vis[i*col + j] = 1;
            if (c == '+') start = i*col + j;
            if (c == '@') stop = i*col + j;
        }
    }
 
    queue<int> q;
    q.push(start);
    dist[start] = 1;
    while (!q.empty()){
 
        int tmp = q.front(); q.pop();
        debug cout << tmp << endl;
 
        for (int i=0; i<4; ++i){
            if (tmp < poz){ ///  ZWYKLY
                if (dist[tmp+moves1[i]] == 0 && vis[tmp+moves[2*i]] && vis[tmp+moves[2*i + 1]]){
                    debug cout << tmp+moves[2*i] << ' ' << tmp+moves[2*i + 1] << endl;
                    dist[tmp+moves1[i]] = dist[tmp] + 1;
                    q.push(tmp+moves1[i]);
                    //par[tmp+moves1[i]] = tmp;
                }
            }
            else if (tmp < pion){ /// POZIOMY
                if (dist[tmp+moves2[i]] == 0 && vis[tmp-poz+movesb[2*i]] && vis[tmp-poz+movesb[2*i + 1]]){
                    debug cout << tmp+movesb[2*i] << ' ' << tmp+movesb[2*i + 1] << endl;
                    dist[tmp+moves2[i]] = dist[tmp] + 1;
                    q.push(tmp+moves2[i]);
                    //par[tmp+moves2[i]] = tmp;
                }
            }
            else { /// PIONOWY
                if (dist[tmp+moves3[i]] == 0 && vis[tmp-pion+movesc[2*i]] && vis[tmp-pion+movesc[2*i + 1]]){
                    debug cout << tmp+movesc[2*i] << ' ' << tmp+movesc[2*i + 1] << endl;
                    dist[tmp+moves3[i]] = dist[tmp] + 1;
                    q.push(tmp+moves3[i]);
                    //par[tmp+moves3[i]] = tmp;
                }
            }
        }
        if (dist[stop] != 0) break;
    }
 
    if (dist[stop] == 0) cout << -1 << endl;
    else cout << dist[stop] - 1 << endl;
/*
    debug while (par[stop] != 0){
        int tmp = par[stop];
        while (tmp > poz) tmp -= poz;
        cout << tmp/col - 1 << ' ' << tmp%col - 1 << endl;
        stop = par[stop];
    }*/
 
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int z;
    cin >> z;
    while(z--){
        solve();
    }
 
}
