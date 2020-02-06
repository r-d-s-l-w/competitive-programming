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

int t, n;
string s[60];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        int counter[2] = {0,0};
        for (int i=0; i<n; ++i)
            cin >> s[i];
        bool easy = 0;
        for (int i=0; i<n; ++i){
            if (s[i].length()%2 == 1) easy = 1;
            for (int j=0; j<s[i].length(); ++j){
                if (s[i][j] == '1') counter[1]++;
                else counter[0]++;
            }
        }

        if (!easy && counter[0]%2){
            cout << n-1 << endl;
        }
        else cout << n << endl;

    }

}
