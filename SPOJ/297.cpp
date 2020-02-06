#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;

constexpr int MOD = 1;
constexpr int INPUT = 100000 + 100;
constexpr int INF = 1e9 + 1;
constexpr double EPS = 1e-9;

ll n, cows;
ll tab[INPUT];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.setf(ios::fixed); cout.precision(20);
    //freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    while (t--){
                cin >> n >> cows;
        for (int i=0; i<n; ++i)
            cin >> tab[i];
        sort(tab, tab+n);

    ///===========================================================================

        ll lo = 1, hi = tab[n-1] - tab[0], mid, temp, cow, ans;
        while (lo <= hi){
            mid = lo + (hi-lo)/2;
            temp = tab[0];
            cow = 1;
            for (int i=1; i<n; ++i){
                if (tab[i] - temp >= mid){
                    ++cow;
                    temp = tab[i];
                }
            }
            if (cow >= cows){
                lo = mid + 1;
                ans = mid;
            }
            else hi = mid - 1;
        }

        cout << ans << "\n";
    }
}
