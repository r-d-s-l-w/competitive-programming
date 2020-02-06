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
 
 
	int n, k, s=0, x;
	cin >> n >> k;
	for (int i=0; i<n; ++i){
		cin >> tab[i];
	}
	sort(tab, tab+n);
	int cc=0, i=0;
	cout << tab[i] << "\n"; cc++;
	while (cc!=k){
	    if (i >= n-1) {
            cout << 0 << "\n";
            cc++; i++;
        }
        else if (tab[i]!=tab[i+1]){
            cout << tab[i+1] - tab[i] << "\n";
            cc++; i++;
        }
        else i++;
	}
}
