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
 
int n, z;
int tab[201000];
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> z;
    for (int i=0; i<n; ++i)
        cin >> tab[i];
    sort(tab,tab+n);
    reverse(tab,tab+n);
    int L = 0, R = n/2;
    int res = 0;
    while (R < n && L < n/2){
        if (tab[L] - tab[R] >= z){
            ++L; ++R; ++res;
        }
        else ++R;
    }
 
    cout << res << endl;
    return 0;
}
