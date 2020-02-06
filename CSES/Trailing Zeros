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
 
constexpr int MOD = 1e9 + 7;
 
int n, res;
vll fives(1000, 1e9 + 1);
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n;
 
    fives[1] = 5;
 
    for (int i=2; fives[i-1] < 1e9; ++i){
        fives[i] = 5;
        fives[i] *= fives[i-1];
    }
 
    for (int i=1; fives[i] != 1e9 + 1; ++i){
        res += n/fives[i];
    }
 
    cout << res << endl;
}
