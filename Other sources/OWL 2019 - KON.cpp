#include <bits/stdc++.h>
#pragma GCC optimize("O3")
 
using namespace std;
 
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
 
constexpr ll IN = 500100;
 
ll M[IN], D[IN], res[IN], n, a, b, q;
bool tab[IN];
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; ++i){
        cin >> tab[i];
    }
 
    for (int i=1; i<=n; ++i){
        res[i] = res[i-1];
        M[i] = M[i-1];
        D[i] = D[i-1];
        if (tab[i]) ++M[i];
        else {
            ++D[i];
            res[i] += M[i];
        }
    }
 
    cin >> q;
    while (q--){
        cin >> a >> b;
        //cout << res[b] << endl;
        cout << res[b] - res[a-1] - M[a-1] * (D[b] - D[a-1]) << endl;
    }
 
    return 0;
}
