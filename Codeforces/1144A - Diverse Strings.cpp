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
 
string s;
int tab[26];
 
 
bool is_diverse(){
    bool is = 1;
    for (int i=0; i<26; ++i){
        tab[i] = 0;
    }
    for (int i=0; i<s.length(); ++i){
        ++tab[s[i] - 97];
    }
    int i = 0;
    while (tab[i] == 0 && i < 26){
        ++i;
    }
    while (tab[i] != 0 && i < 26){
        if (tab[i] != 1) is = false;
        ++i;
    }
    while (tab[i] == 0 && i < 26){
        ++i;
    }
    if (i != 26) is = false;
    return is;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while (n--){
        cin >> s;
        if (is_diverse()) cout << "Yes\n";
        else cout << "No\n";
    }
 
    return 0;
}
