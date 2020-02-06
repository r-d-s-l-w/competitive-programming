/// Radoslaw Mysliwiec 2020
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define F first
#define S second
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
#define dd cout << " debug";

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;
using ordered_set = tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n;
    cin >> t;
    while (t--){
        cin >> n; vi tab(n);

        for (int i=0; i<n; ++i)
            cin >> tab[i];

        if (n == 1) {
            cout << "Yes\n";
            continue;
        }
        else if (n == 2){
            if (tab[0] != 0 || tab[1] != 0)
                cout << "Yes\n";
            else cout << "No\n";
            continue;
        }

        int parz = 0;
        if (n%2 == 0) parz = 1;
        bool da_sie = 1;

        for (int i=0; i<n; ++i){
            int L = i;
            int R = n - i - 1;
            if (tab[i] < min(L, R)) da_sie = 0;
        }
        if (parz){
            if (tab[n/2] == tab[n/2 - 1] && tab[n/2 - 1] == n/2 - 1) da_sie = 0;
        }

        if (da_sie) cout << "Yes\n";
        else cout << "No\n";
    }

}

 
