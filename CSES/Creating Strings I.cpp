/// Radoslaw Mysliwiec 2020
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;
 
string s;
vector<string> res;
vector<string> res2;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> s;
 
    sort(ALL(s));
 
    do{
        res.PB(s);
    }while(next_permutation(ALL(s)));
 
    sort(ALL(res));
 
    for (int i=0; i<res.size(); ++i){
        if (i == 0 || res[i-1] != res[i]){
            res2.PB(res[i]);
        }
    }
    cout << res2.size() << endl;
    for (auto u: res2)
        cout << u << endl;
 
