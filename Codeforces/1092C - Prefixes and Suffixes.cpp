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

string s[210];
string a, b;
char res[210];
bool prefa[110], sufa[110], prefb[110], sufb[110];
int n;

bool is_suf(string y, string x){
    bool res = 1;
    for (int i=0; i<y.length(); ++i)
        if (x[i+x.length() - y.length()] != y[i]) res = 0;
    return res;
}

bool is_pref(string y, string x){
    bool res = 1;
    for (int i=0; i<y.length(); ++i)
        if (x[i] != y[i]) res = 0;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<2*n-2; ++i){
        cin >> s[i];
        if (s[i].length() == n-1){
            if (a == "") a = s[i];
            else b = s[i];
        }
    }

    a += b[n-2];
    b += a[n-2];
    bool poss = 1;
    for (int i=0; i<2*n-2; ++i){
        if (!prefa[s[i].length()] && is_pref(s[i],a)){
            res[i] = 'P';
            prefa[s[i].length()] = 1;
        }
        else if (!sufa[s[i].length()] && is_suf(s[i],a)){
            sufa[s[i].length()] = 1;
            res[i] = 'S';
        }
        else poss = 0;
    }
    if (poss){
        for (int i=0; i<2*n-2; ++i)
            cout << res[i];
        return 0;
    }

    poss = 1;
    for (int i=0; i<2*n-2; ++i){
        if (!prefb[s[i].length()] && is_pref(s[i],b)){
            res[i] = 'P';
            prefb[s[i].length()] = 1;
        }
        else if (!sufb[s[i].length()] && is_suf(s[i],b)){
            sufb[s[i].length()] = 1;
            res[i] = 'S';
        }
        else poss = 0;
    }
    if (poss){
        for (int i=0; i<2*n-2; ++i)
            cout << res[i];
        return 0;
    }
    cout << "NO\n";
}
