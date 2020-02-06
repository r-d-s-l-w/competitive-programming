// Radoslaw Mysliwiec 2019
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB emplace_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;
 
int tab[200100], n;
vi x, y;
bool poss = 1;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> tab[i];
    }
    sort(tab,tab+n);
    int temp = -1;
    for (int i=0; i<n; ++i){
        if (tab[i] > temp) x.PB(tab[i]);
        else y.PB(tab[i]);
        temp = tab[i];
    }
    temp = -1;
    for (int i=0; i<y.size(); ++i){
        if (y[i] == temp) poss = 0;
        temp = y[i];
    }
    reverse(ALL(y));
    if (poss){
        cout << "YES\n";
        cout << x.size() << endl;
        for (int i=0; i<x.size(); ++i)
            cout << x[i] << ' ';
        cout << endl << y.size() << endl;
        for (int i=0; i<y.size(); ++i)
            cout << y[i] << ' ';
        cout << endl;
 
    }
    else cout << "NO\n";
 
 
 
    return 0;
}
