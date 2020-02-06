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
 
void solve2(int n){
    vector<pair<string, int>> tmp;
    vector<vi> tab(n+1);
    vi sql;
    for(int i=1; i<=n; ++i){
        int m; cin >> m;
        for (int j=1; j<=m; ++j){
            string s; cin >> s;
            tmp.PB({s,i});
        }
        sql.PB(i);
    }
    sort(ALL(tmp));
 
    for (int i=0; i<tmp.size(); ++i)
        tab[tmp[i].S].PB(i+1);
    /*
    for (int i=1; i<=n; ++i){
        for (auto u: tab[i])
            cout << u << ' ';
        cout << endl;
    }*/
    auto start = chrono::high_resolution_clock::now();
    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed;
    int k = 0;
    do{
        int it = 0;
        for (int i=0; i<sql.size(); ++i){
            auto tmp2 = upper_bound(ALL(tab[sql[i]]), it);
            if (tmp2 == tab[sql[i]].end()){
                cout << "NIE\n";
                for (auto u: sql)
                    cout << u << ' ';
                cout << endl;
                return;
            }
            else it = *tmp2;
        }
        random_shuffle(ALL(sql));
        ++k; int diff;
        if (k%1000 == 0){
            stop = chrono::high_resolution_clock::now();
            elapsed = stop - start;
        }
    } while(elapsed.count() < 48);
 
    cout << "TAK\n";
}
 
void solve(){
    int n;
    cin >> n;
 
    if (n > 10){
        solve2(n);
        return;
    }
 
    vector<pair<string, int>> tmp;
    vector<vi> tab(n+1);
    vi sql;
    for(int i=1; i<=n; ++i){
        int m; cin >> m;
        for (int j=1; j<=m; ++j){
            string s; cin >> s;
            tmp.PB({s,i});
        }
        sql.PB(i);
    }
    sort(ALL(tmp));
 
    for (int i=0; i<tmp.size(); ++i)
        tab[tmp[i].S].PB(i+1);
    /*
    for (int i=1; i<=n; ++i){
        for (auto u: tab[i])
            cout << u << ' ';
        cout << endl;
    }*/
 
    do{
        int it = 0;
        for (int i=0; i<sql.size(); ++i){
            auto tmp2 = upper_bound(ALL(tab[sql[i]]), it);
            if (tmp2 == tab[sql[i]].end()){
                cout << "NIE\n";
                for (auto u: sql)
                    cout << u << ' ';
                cout << endl;
                return;
            }
            else it = *tmp2;
        }
 
    } while(next_permutation(ALL(sql)));
 
    cout << "TAK\n";
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int z;
    cin >> z;
    while(z--){
        solve();
    }
}
