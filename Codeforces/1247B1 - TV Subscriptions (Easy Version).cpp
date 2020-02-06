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

int n, k, d;
int tab[1001000];
int coun[1001000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cases;
    cin >> cases;
    while (cases--){
        cin >> n >> k >> d;

        for (int i=0; i<n; ++i){
            cin >> tab[i];
        }

        int R = 0, L = 0, ile_roznych = 0;
        for (; R<d; ++R){
            if (coun[tab[R]] == 0)
                ile_roznych++;
            coun[tab[R]]++;
        }

        int res = ile_roznych;
        while (R != n){

            if (coun[tab[L]] == 1)
                ile_roznych--;
            coun[tab[L]]--;
            ++L;

            if (coun[tab[R]] == 0)
                ile_roznych++;
            coun[tab[R]]++;
            //cout << L << ' ' << R << ' ' << ile_roznych << endl;
            ++R;
            res = min(res,ile_roznych);
        }
        while (L != n){
            coun[tab[L]]--;
            ++L;
        }

        cout << res << endl;
    }



}
