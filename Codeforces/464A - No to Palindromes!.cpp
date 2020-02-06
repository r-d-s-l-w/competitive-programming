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

string s;
int n, p;
vi poss[1010];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> p;
    cin >> s;
    reverse(ALL(s));
    int it = 100000;
    for (int j=0; j<n; ++j){
        for (int i=s[j]+1; i<p+97; ++i){
            if (i != s[j+1] && i != s[j+2]){
                s[j] = i;
                it = j;
                //cout << i << endl;
                break;
            }
        }
        if (it != 100000) break;
    }
    if (it == 100000) {
        cout << "NO\n";
        return 0;
    }
    for (int i=it-1; i>=0; --i){
        for (int j=97; j<p+97; ++j){
            if (j != s[i+1] && j != s[i+2]){
                s[i] = j;
                break;
            }
        }
    }

    reverse(ALL(s));
    cout << s << endl;

}
