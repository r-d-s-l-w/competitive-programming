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

int n, tab[200200];
vi wyst[200200];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cases;
    cin >> cases;
    while (cases--){
        cin >> n;
        for (int i=1; i<=n; ++i){
            cin >> tab[i];
            //wyst[tab[i]].PB(i);
            wyst[i].clear();
        }
        int res = 99999999; int R = 1;
        for (int L=1; L<n;){

            while(wyst[tab[R]].size() != 1 && tab[R] != 0){
                wyst[tab[R]].PB(R);
                ++R;
            }
            //cout << " " << wyst[tab[R]].size() << endl;

            while(wyst[tab[R]].size() == 1){
                wyst[tab[L]].pop_back();
                ++L;
                //cout <<"XD";
            }

            if (R <= n) {
                    //cout << ' ' << L << ' ' << R << endl;
                    res = min(res,R-L+2);
            }

            if (R > n) break;

        }
        if (res == 99999999) cout << -1 << endl;
        else cout << res << endl;
    }
}
