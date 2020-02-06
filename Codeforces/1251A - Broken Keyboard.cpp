/// Radoslaw Mysliwiec 2019
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

int n;
bool is[200];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        for (int i=0; i<200; ++i){
            is[i] = 0;
        }
        if (s.length() == 1) {
            cout << s[0] << endl;
            continue;
        }
        int len = s.length() - 1;
        int tmp = s[0]; int c = 0;
        for (int i=0; i<=len+1; ++i){
            if (s[i] == tmp) ++c;
            else {
                if(c%2) is[s[i-1]] = 1;
                c = 1;
                tmp = s[i];
            }
        }
        if (s[len] != s[len-1]) is[s[len]] = 1;
        if (s[0] != s[1]) is[s[0]] = 1;

        for (int i=0; i<200; ++i){
            if (is[i] == 1) cout << char(i);
        } cout << endl;
    }

}
