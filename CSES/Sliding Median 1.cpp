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
 
ordered_set s;
int n, k;
vi tab(200200);
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> k;
    int tmp = 1;
    for (int i=1; i<=n; ++i){
        cin >> tab[i];
        s.insert({tab[i], i});
        if (i >= k){
            cout << (*s.find_by_order((k-1)/2)).first << ' ';
            s.erase({tab[i - k + 1], i - k + 1});
        }
    }
}
