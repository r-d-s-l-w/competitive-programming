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
 
int moves[4] = {-col,col,1,-1};
vector<bool> vis(1010000,1);
char c;
int n, m;
 
void bfs(int a){
    queue<int> q;
    q.push(a);
    vis[a] = 1;
    while (!q.empty()){
        int tmp = q.front(); q.pop();
        for(int i=0; i<4; ++i){
            if (vis[tmp+moves[i]] == 0){
                q.push(tmp+moves[i]);
                vis[tmp+moves[i]] = 1;
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
            if (c == '.') vis[i*col+j] = 0;
        }
    }
    int res = 0;
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            if (!vis[i*col+j]){
                bfs(i*col+j);
                ++res;
            }
        }
    }
 
    cout << res << endl;
}
