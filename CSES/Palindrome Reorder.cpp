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
vi tab(100, 0);
vector<char> res;
vector<char> mid;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> s;
    for (int i=0; i<s.length(); ++i){
        ++tab[s[i]];
    }
    for (int i='A'; i<='Z'; ++i){
        if (tab[i] % 2) {
            while (tab[i] > 0){
                mid.PB(i);
                --tab[i];
            }
        }
        while (tab[i] > 0){
            res.PB(i);
            tab[i] -= 2;
        }
    }
 
    if (mid.size() > 1 && mid[0] != mid[mid.size() - 1]){
        cout << "NO SOLUTION\n";
        return 0;
    }
 
    for (auto u: res) cout << u;
    reverse(ALL(res));
    for (auto u: mid) cout << u;
    for (auto u: res) cout << u;
    cout << endl;
}
