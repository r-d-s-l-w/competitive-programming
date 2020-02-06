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
 
constexpr ll INF = 1e9 + 1;
 
int q, tab[15][15], n, maks, licznik, ruch[30];
bool pion[30], poziom[30], ukos_l[30], ukos_r[30];
 
void ini(){
    for (int i=0; i<30; ++i){
        pion[i] = 0;
        poziom[i] = 0;
        ukos_l[i] = 0;
        ukos_r[i] = 0;
    }
}
 
void solve(int i){
    if (i == n) {
        int temp = 0;
        for (int i=0; i<n; ++i)
            temp += tab[i][ruch[i]];
        maks = max(temp,maks);
    }
    for (int j = 0; j < n; ++j){
        if (!pion[j] && !poziom[i] && !ukos_r[i+j] && !ukos_l[n-1-i+j]){
            pion[j] = true; poziom[i] = true; ruch[i] = j;
            ukos_r[i+j] = true; ukos_l[n-1-i+j] = true;
            solve(i+1);
            pion[j] = false; poziom[i] = false;
            ukos_r[i+j] = false; ukos_l[n-1-i+j] = false;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> q;
    while (q--){
        ini();
        cin >> n;
        for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            cin >> tab[i][j];
        solve(0);
        cout << maks << endl;
        maks = 0;
    }
}
