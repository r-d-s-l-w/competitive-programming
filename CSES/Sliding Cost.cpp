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
ll n, k;
vll tab(200200);
vll median(200200);
vll cost(200200, 0);
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> k;
 
    for (int i=1; i<=n; ++i)
        cin >> tab[i];
 
    for (int i=1; i<=n; ++i){
        s.insert({tab[i], i});
        if (i >= k){
            median[i - k + 1] = (*s.find_by_order((k-1)/2)).F;
            s.erase({tab[i - k + 1], i - k + 1});
        }
    }
 
    for (int i=1; i<=k; ++i)
        cost[1] += abs(median[1] - tab[i]);
 
    for (int L=2; L<=n-k+1; ++L){
        cost[L] = cost[L - 1];
        cost[L] += abs(tab[L + k - 1] - median[L - 1]) - abs(tab[L - 1] - median[L - 1]);
        if (k % 2 == 0 && median[L] > median[L - 1])
            cost[L] -= 2*abs(median[L] - median[L - 1]);
        else if (k % 2) cost[L] -= abs(median[L] - median[L - 1]);
    }
 
    for (int i=1; i<=n - k + 1; ++i)
        cout << cost[i] << ' ';
 
}
