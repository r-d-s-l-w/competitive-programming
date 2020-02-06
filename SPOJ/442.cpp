#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1001];
bool visited[1001];
queue<int> q;

void DFS(int s){
    if (visited[s]) return;
    visited[s] = true;
    cout << s << ' ';
    for (int i=0; i<adj[s].size(); i++){
        DFS(adj[s][i]);
    }
}

void vclear (int s){
    for (int i=0; i<=s; i++)
        visited[i] = false;
}

void BFS(int x)
{
    visited[x]=true;
    q.push(x);
    while (!q.empty()){
        int s = q.front(); q.pop();
        cout << s << ' ';
        for (int i=0; i<adj[s].size(); i++){
            if (visited[adj[s][i]]) continue;
            visited[adj[s][i]] = true;
            q.push(adj[s][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int k=1; k<=t; k++)
    {
        int m, n, o, a;
        cin >> n;

        for (int i=0; i<n; i++)
        {
            cin >> o >> m;
            while (m--)
            {
                cin >> a;
                adj[o].push_back(a);
                adj[a].push_back(o);
            }
        }
        int v, i;
        cout << "graph " << k << "\n";
        while(cin >> v >> i)
        {
            if (v==0&&i==0) break;
            i==0?DFS(v):BFS(v);
            cout << "\n";
            vclear(n);
        }
        for (int i=0; i<=n; i++){
            adj[i].clear();
        }
    }
}
