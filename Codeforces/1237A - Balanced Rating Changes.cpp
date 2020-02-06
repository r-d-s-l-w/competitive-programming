/// Radoslaw Mysliwiec 2019
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

int n;
int tab[100100];

int sufit(int a){
    if (a < 0) return a/2;
    return a/2 + 1;
}

int podloga(int a){
    if (a > 0) return a/2;
    return a/2 - 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> tab[i];
    }

    bool xd = 0;
    for (int i=0; i<n; ++i){
        if (tab[i]%2 == 0) cout << tab[i]/2 << endl;
        else {
            if (xd){
                cout << sufit(tab[i]) << endl;
                xd = !xd;
            }
            else {
                cout << podloga(tab[i]) << endl;
                xd = !xd;
            }
        }
    }
}
