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
int n;
bool xd;
 
bool cos(string x){
    for (int i=1; i<x.length(); ++i){
        if (x[i] - x[i-1] == 1) return 1;
        else if (x[i] - x[i-1] == -1) return 1;
    } return 0;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--){
        cin >> s;
        xd = 1;
        sort(ALL(s));
        string a, b;
        a = s[0];
        for (int i=1; i<s.length(); ++i){
            if (s[i] != s[i-1]) xd = !xd;
            if (xd) a += s[i];
            else b += s[i];
        }
        if (cos(b+a) && cos(a+b))  cout << "No answer\n";
        else if (!cos(b+a)) cout << b + a << endl;
        else cout << a + b << endl;
    }
 
    return 0;
}
