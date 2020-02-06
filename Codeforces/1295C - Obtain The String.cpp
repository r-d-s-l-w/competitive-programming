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

const int MOD = 998244353;

int T;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--){
        string s, t;
        cin >> s >> t;
        bool no = 0;
        int n = t.length();
        reverse(ALL(t));reverse(ALL(s));
        vi tab[26];

        for (int i=0; i<s.length(); ++i){
            tab[s[i]-'a'].PB(i);
        }
        int res = 0; int it = 0;
        while(++res){
            int actual = -1;

            while(true){
                if (tab[t[it]-'a'].size() == 0){
                    cout << -1 << endl;
                    no = 1;
                    break;
                }
                else {
                    auto u = upper_bound(ALL(tab[t[it]-'a']), actual);
                    if (u == tab[t[it]-'a'].end()) break;
                    else {
                        actual = *u;
                        ++it;
                    }
                }
                if (it == n) break;
            }
            if (it == n) break;
            if (no) break;
        }
        if (!no) cout << res << endl;

    }
}

 
