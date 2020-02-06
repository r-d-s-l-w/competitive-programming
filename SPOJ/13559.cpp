#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, a, b, wynik;
    cin >> t;
    while (t--)
    {
        cin >> n; wynik=0;
        vector <int> adj[n];
        int tab[n];
        for (int i=0; i<n; i++) tab[i]=1;
        for (int i=1; i<n; i++)
        {
            cin >> a >> b;
            addEdge(adj, a, b);
        }
        for (int i=n-1; i>=0; i--)
        {
            for (int j=0; j<adj[i].size(); j++)
            {
                if (adj[i][j]>i) tab[i]+=tab[adj[i][j]]+1;
            }
            wynik+=tab[i];
        }
        cout << wynik << "\n";
    }
}

