/// while (clock()<=69*CLOCKS_PER_SEC)
/// #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
/// #pragma GCC optimize("Ofast")
/// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
/// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
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
 
 
int tab[101000];
 
 
int main(){
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.setf(ios::fixed); cout.precision(20);
    int n, maks=0;
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> tab[i];
 
    }
    cout << n+1 << endl;
    for (int i=n-1; i>=0; --i){
        cout << 1 << ' ' << i+1 << ' ' <<  n+(i-(tab[i]%n)) << "\n";
        for (int j=0; j<i+1; ++j) tab[j]+=n+(i-(tab[i]%n));
    }
    cout << 2 << ' ' << n << ' ' << n << "\n";
 
    //cout << endl;
    //for (int i=0; i<n; ++i) cout << tab[i]%n << ' ';
 
 
 
 
}
