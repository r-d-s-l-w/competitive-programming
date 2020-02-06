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
 
const int col = 1001;
vi moves = {-1, 1, -col, col};
vector<char> moves2 = {'L','R','U','D'};
vector<bool> vis(1100000, 1);
vector<pair<int,char>> res1;
vector<pair<int,char>> res2;
vi monsters, start;
int n, m, wynik;
vector<char> c(1100000);
 
vector<pair<int,char>> bfs(vi a, vector<bool> visited){
    vector<pair<int,char>> res(1100000, {1e9,-1});
    queue<int> q;
    for (auto u: a){
        visited[u] = true;
        q.push(u);
        res[u].F = 0;
    }
    while(!q.empty()){
        int tmp = q.front(); q.pop();
        for (int i=0; i<4; ++i){
            if (!visited[tmp + moves[i]]){
                visited[tmp + moves[i]] = 1;
                q.push(tmp + moves[i]);
                res[tmp + moves[i]].F = res[tmp].F + 1;
                res[tmp + moves[i]].S = moves2[i];
            }
        }
    }
    return res;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
 
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            cin >> c[i*col + j];
            if (c[i*col + j] != '#') {
                vis[i*col + j] = 0;
            }
            if (c[i*col + j] == 'M'){
                monsters.PB(i*col + j);
            }
            if (c[i*col + j] == 'A'){
                start.PB(i*col + j);
            }
        }
    }
 
    res1 = bfs(start, vis);
    res2 = bfs(monsters, vis);
 
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            if (wynik) break;
            if (c[i*col + j] == '#') continue;
            if (i != 1 && i != n && j != 1 && j != m) continue;
 
            if (res1[i*col + j].F < res2[i*col + j].F){
                wynik = i*col + j;
            }
        }
    }
 
    if (!wynik){
        cout << "NO\n";
        return 0;
    }
 
    cout << "YES\n";
    cout << res1[wynik].F << endl;
    vector<char> tmp;
    while(wynik != start[0]){
        if (res1[wynik].S == 'L'){
            tmp.PB('L');
            wynik += 1;
        }
        else if (res1[wynik].S == 'R'){
            tmp.PB('R');
            wynik -= 1;
        }
        else if (res1[wynik].S == 'U'){
            tmp.PB('U');
            wynik += col;
        }
        else if (res1[wynik].S == 'D'){
            tmp.PB('D');
            wynik -= col;
        }
    } reverse(ALL(tmp));
    for (auto u: tmp)
        cout << u;
    cout << endl;
 
 
}
