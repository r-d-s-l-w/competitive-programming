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

#define MAXN 8000100

int spf[MAXN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.setf(ios::fixed); cout.precision(20);

    ll t, x;

    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
    for (int i=3; i*i<MAXN; i++){
        if (spf[i] == i){
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }

    cin >> t;
    while (t--){
        cin >> x;
        cout << spf[x];
        x = x / spf[x];
        while (x != 1){
            cout << '*' << spf[x];
            x = x / spf[x];
        }
        cout << "\n";
    }
}
