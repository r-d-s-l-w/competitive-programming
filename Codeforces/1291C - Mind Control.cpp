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

void solve(){
    int n, m, k;

    cin >> n >> m >> k;

    vi tab(n+1), poss;
    int dlugosc = n - m + 1;

    for (int i=1; i<=n; ++i)
        cin >> tab[i];

    for (int L=1; L+(n-m) <= n; ++L){
        int tmp = max(tab[L], tab[L+(n-m)]);
        poss.PB(tmp);
        //cout << ' ' << tmp << ' ';
    }

    int res = *min_element(ALL(poss));

    k = min(k, m-1);

    int Size = poss.size();

    for (int i=0; i<= k; ++i){
        int minn = int(1e9 + 1);
        for (int j=i; j<i+(Size - k); ++j){
            minn = min(minn, poss[j]);
            //cout << ' ' << poss[j];
        } //cout << endl;
        res = max(minn, res);
    }

    cout << res << endl;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

}

 
