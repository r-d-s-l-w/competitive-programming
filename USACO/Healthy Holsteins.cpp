/*
ID: radek.m1
TASK: holstein
LANG: C++11
*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

#define F first
#define S second
#define PB emplace_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;

constexpr ll MOD = 1000000007;
constexpr ll INI = -1;
constexpr ll IN = 350 + 10;
constexpr ll INF = 1e9 + 1;
constexpr ld EPS = 1e-9;

bool vis[100000];
int V,G,v[30],g[20][30];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    freopen("holstein.in","r",stdin); freopen("holstein.out","w",stdout);
    cin >> V;
    for (int i=0; i<V; ++i)
        cin >> v[i];
    cin >> G;
    for (int i=0; i<G; ++i)
        for (int j=0; j<V; ++j)
            cin >> g[i][j];

    vi res;
    for (int i=0; i<(1<<G); ++i){
        vi tmp(30,0); vi temp;
        for (int j=0; j<G; ++j){
            if (i&(1<<j)){
                for (int k=0; k<V; ++k)
                    tmp[k] += g[j][k];
                temp.PB(j+1);
            }
        }
        bool yes = 1;
        for (int k=0; k<V; ++k)
            if (tmp[k] < v[k]) yes = 0;
        if (yes && (res.size() > __builtin_popcount(i) || res.size() == 0))
            res = temp;
    }

    sort(ALL(res));
    cout << res.size();
    for (auto u: res)
        cout << ' '<< u; cout << endl;
}
