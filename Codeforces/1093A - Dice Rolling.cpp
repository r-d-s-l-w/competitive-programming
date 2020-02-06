// Radek M
/// while (clock()<=69*CLOCKS_PER_SEC)
/// #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
/// #pragma GCC optimize("Ofast")
/// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
/// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ALL(x) (x).begin(), (x).end()
#define MOD 1000000007
 
using namespace __gnu_pbds;
using namespace std;
 
using ll=long long;
using ld = long double;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;
const ll mod=1000*1000*1000+7;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.setf(ios::fixed); cout.precision(20);
    int t;
    cin >> t;
    while (t--)
    {
 
        int x;
        cin >> x;
        if (x == 1) cout << 1 << endl;
        else cout << x/2 << "\n";
    }
}
