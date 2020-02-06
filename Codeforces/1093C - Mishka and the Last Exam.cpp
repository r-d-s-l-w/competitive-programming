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
 
ll tab[200000];
ll arr[300000];
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.setf(ios::fixed); cout.precision(20);
    int n;
    cin >> n;
    for (int i=0; i<n/2; ++i){
        cin >> tab[i];
    }
    arr[n-1] = tab[0];
    for (int i=1; i<n/2; ++i){
        if (tab[i] <= tab[i-1]){
            arr[i] = arr[i-1];
            arr[n-i-1] = tab[i] - arr[i];
        }
        else {
            arr[n-i-1] = arr[n-i];
            arr[i] = tab[i] - arr[n-i];
        }
    }
    for (int i=0; i<n; ++i) cout << arr[i] << ' ';
}
