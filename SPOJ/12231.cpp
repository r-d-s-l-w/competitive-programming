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

string s; int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--){
        cin >> s;
        string res = "";
        char tmp = 'A';
        for (int i=s.length()-1; i>=0; --i)
            if (s[i] >= tmp) {
                tmp = s[i];
                res += s[i];
            }
        reverse(ALL(res));
        cout << res << endl;
    }

    return 0;
}
