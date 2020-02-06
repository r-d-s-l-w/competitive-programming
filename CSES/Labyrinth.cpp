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
int n, m, start, dest;
vector<pair<int,char>> moves = {{1,'R'},{-1,'L'},{col,'D'},{-col,'U'}};
vector<bool> vis(1100000,1);
vector<int> dist(1100000,-1);
vector<pair<int,char>> from(1100000,{-1,-1});
char c;
 
void bfs(int a){
    vis[a] = true;
    dist[a] = 0;
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int tmp = q.front(); q.pop();
        for (int i=0; i<4; ++i){
            if (!vis[tmp + moves[i].F]){
                dist[tmp + moves[i].F] = dist[tmp] + 1;
                from[tmp + moves[i].F].S = moves[i].S;
                from[tmp + moves[i].F].F = tmp;
                q.push(tmp + moves[i].F);
                vis[tmp + moves[i].F] = 1;
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            cin >> c;
            if (c != '#'){
                vis[i*col + j] = 0;
            }
            if (c == 'A'){
                start = i*col + j;
            }
            if (c == 'B'){
                dest = i*col + j;
            }
        }
    }
 
    bfs(start);
 
    if (dist[dest] == -1) cout << "NO\n";
    else {
        cout << "YES\n";
        cout << dist[dest] << endl;
        vector<char> res;
        while(from[dest].S != -1){
            res.PB(from[dest].S);
            dest = from[dest].F;
        }
        reverse(ALL(res));
        for (auto u: res)
            cout << u;
        cout << endl;
    }
 
}
