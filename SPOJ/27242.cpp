/// Radoslaw Mysliwiec 2019

/// https://pl.spoj.com/problems/AL_28_07/

/// zachlan, sortowanie, binsearch po wyniku (trik)

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB emplace_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;

constexpr int INI = -1;
constexpr ll INF = 1e9 + 1;
constexpr int IN = 100000 + 10;
constexpr int MOD = 1e9 + 7;
constexpr ld EPS = 1e-9;

int t, n, m;
pi tab[IN];

bool check(int x){
    int tmp = m;
    for(int i=n-1; i>=0; --i){
        if (tab[i].S > x) continue;

        if (tab[i].F - 2*tmp < 1)
            return 0;

        tmp -= tab[i].F - 2*tmp;

        if (tmp <= 0) return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
    cin >> t;
    while (t--){
        cin >> n >> m;
        for (int i=0; i<n; ++i){
            cin >> tab[i].F;
            tab[i].S = i;
        }
        sort(tab,tab+n);
        if (!check(n-1)){
            cout << "NIE\n";
        }
        else{
            int L = 0, R = n-1;
            while (L < R){
                int mid = (L+R)/2;
                if (check(mid)) R = mid;
                else L = mid + 1;
            }
            cout << L + 1<< endl;
        }

    }

}
