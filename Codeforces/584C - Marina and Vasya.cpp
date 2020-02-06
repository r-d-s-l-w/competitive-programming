// Radoslaw Mysliwiec 2019
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

int n, x;
string s, t;
char inne[100100];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    cin >> s >> t;
    int eq = 0;
    for (int i=0; i<n; ++i)
        if (s[i] != t[i]) ++eq;

    for (int i=0; i<n; ++i){
        if ('a' != s[i] && 'a' != t[i])
            inne[i] = 'a';
        else if ('b' != s[i] && 'b' != t[i])
            inne[i] = 'b';
        else if ('c' != s[i] && 'c' != t[i])
            inne[i] = 'c';
    }

    if (x < (eq+1)/2) {
        cout << -1 << endl;
        return 0;
    }
    int a, b, c, d;
    if (x >= eq) {
        a = eq; // ile podwojnych
        b = 0; // ile pojedynczych 1
        c = 0; // ile pojedynczych 2
        d = x - eq; // ile rownych zmienic
    }
    else {
        a = 2*x - eq;
        b = eq - x;
        c = eq - x;
        d = 0;
    }
    //cout << a << ' ' << b << ' ' << c << ' ' << d << endl;

    for (int i=0; i<n; ++i){
        if (s[i] != t[i]){
            if (a > 0){
                --a;
                s[i] = inne[i];
            }
            else if (b > 0){
                --b;
                s[i] = t[i];
            }
        }
        else if (d > 0){
            --d;
            s[i] = inne[i];
        }
    }
    cout << s << endl;
}
