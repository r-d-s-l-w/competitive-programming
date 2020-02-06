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
    string s;
    cin >> t;
    while(t--){
        cin >> n >> s;
        vi niep, parz;
        for (int i=0; i<n; ++i){
            if ((s[i] - '0') % 2) niep.PB(s[i] - '0');
            else parz.PB(s[i] - '0');
        }
        if (niep.size() <= 1) cout << -1 << endl;
        else cout << niep[0] << niep[1] << endl;

    }
}

 
