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
 
int tab[310][310][30];
int pref[310][310], n, m, k;
char c[310][310];
 
int count_from(int a, int b){
    int res = 0;
    for (int i=a; i<=n; ++i)
    for (int j=b; j<=m; ++j){
        int temp = 0;
        for (int x = 0; x<26; ++x)
            if (tab[i][j][x] - tab[i][b-1][x] - tab[a-1][j][x] + tab[a-1][b-1][x] > 0) ++temp;
        //cout << a << ' ' << b << ' ' << i << ' ' << j << endl;}
        if (temp == k) ++res; //cout << "       " << i << ' ' << j << endl;}
    }
    return res;
}
 
int sol(){
    int res = 0;
    for (int i=1; i<=n; ++i)
    for (int j=1; j<=m; ++j)
        res += count_from(i,j);
    return res;
}
 
void precompute(){
    for (int i=1; i<=n; ++i)
    for (int j=1; j<=m; ++j){
        for (int k=0; k<26; ++k)
            tab[i][j][k] = tab[i][j-1][k] + tab[i-1][j][k] - tab[i-1][j-1][k];
        ++tab[i][j][c[i][j]-65];
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i=1; i<=n; ++i)
    for (int j=1; j<=m; ++j){
        cin >> c[i][j];
        tab[i][j][c[i][j]-65] = 1;
    }
    precompute();
    cout << sol() << endl;
 
    return 0;
}
