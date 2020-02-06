#pragma GCC optimize("O3")
#include<bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
bool is[1000100];
int z, k, n, m, tab[1000100], nextt[1000100], res, sz;
int tmp[1000100];
priority_queue<pair<int,int> > pq;
 
void ini(){
    for (int i=0; i<=m; ++i)
        is[i] = 0; res = 0;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> z;
    while(z--){
 
        cin >> k >> m >> n; ini();
        for (int i=1; i<=n; ++i)
            cin >> tab[i];
 
        for (int i=1; i<=m; ++i)
            tmp[i] = 1e9;
 
        for (int i=n; i>0; --i){
            nextt[i] = tmp[tab[i]];
            tmp[tab[i]] = i;
        }
        sz = 0;
        for (int i=1; i<=n; ++i){
            if (!is[tab[i]]){
                if (sz == k){
                    is[pq.top().second] = false; --sz;
                    pq.pop();
                }
                is[tab[i]] = true; ++sz;
                ++res;
            }
            pq.push({nextt[i],tab[i]});
        }
        while (!pq.empty()) pq.pop();
        cout << res << endl;
    }
 
}
