// Radoslaw Mysliwiec 2019
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
 
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
using pll = pair<ll,ll>;
using matrix = vector<vll>;
 
int n;
int p[100100], c[100100];
vi children[100100];
bool respect[100100];
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; ++i){
        cin >> p[i] >> c[i];
        children[p[i]].PB(i);
        if (c[i] == 0 && p[i] != -1)
            respect[p[i]] = true;
    }
    bool xd = true;
    for (int i=1; i<=n; ++i){
        if (respect[i] == 0 && c[i] == 1){
            cout << i << ' ';
            xd = false;
        }
    }
 
    if(xd) cout << -1 << endl;
 
 
    return 0;
}
