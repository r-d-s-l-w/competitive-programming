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

vll big_int (string x){
    vll result;
    int length = x.length();
    reverse(ALL(x));
    for (int i = 0; i < 1800 - length; ++i)
        x += '0';
    for (int i = 0; i < x.length(); i+=9){
        ll temp = 1, sum = 0;
        for (int j = 0; j < 9; ++j){
            sum += temp * (x[i + j] - 48);
            temp *= 10;
        }
        result.push_back(sum);
    }
    return result;
}

vll BI_add (string x, string y){
    vll a = big_int(x);
    vll b = big_int(y);
    vll result;
    ll sum;
    for (int i = 0; i < a.size(); ++i){
        sum = a[i] + b[i];
        if (sum > 999999999) a[i+1]++;
        result.push_back(sum % 1000000000);
    }
    return result;
}

int main(){
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.setf(ios::fixed); cout.precision(20);
    string a, b; int k;
    cin >> k;
    for (int i=0; i<k; ++i){
        cin >> a >> b;
        vll nr = BI_add(a,b);
        for (int i=nr.size() - 1; i>=0; --i) if (nr[i]) cout << nr[i]; cout  << endl;
    }
}
