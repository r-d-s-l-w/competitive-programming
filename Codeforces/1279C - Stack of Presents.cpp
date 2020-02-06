/// Radoslaw Mysliwiec 2020
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using vll = vector<ll>;

int t, n, m, x;
bool is[100100];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){
        ll res = 0;
        cin >> n >> m;
        vi a, b;
        int sz = n;
        for (int i=0; i<n; ++i){
            is[i+1] = 0;
            cin >> x;
            a.PB(x);
        }
        for (int i=0; i<m; ++i){
            cin >> x;
            b.PB(x);
        }
        int it = 0;
        for (int i=0; i<b.size(); ++i){
            if (is[b[i]]) ++res;
            else {
                while (a[it] != b[i]){
                    is[a[it]] = 1;
                    ++it;
                }
                res += 2*(it - i) + 1;
            }
            //cout << " " << res << endl;

        }

        cout << res << endl;
    }
}
