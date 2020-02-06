/// Radoslaw Mysliwiec 2020
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;

const int MOD = 998244353;

int t;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){
        int n; int res = 0;
        string s; int x;
        map<int, int> mp;
        cin >> n >> x; if (x == 0) ++res;
        cin >> s;
        int xx = 0;
        for (auto u: s){
            if (u == '1') ++xx;
            else --xx;
        }
        if (xx > 0){
            for (int i=0; i<s.length(); ++i){
                s[i] == '0' ? s[i] = '1' : s[i] = '0';
            }
            x *= -1;
        }



        int minn = 0, maxx = 0;
        vi tab(s.length());


        if (s[0] == '0') tab[0] = 1;
        else tab[0] = -1;
        minn = min(minn, tab[0]);
        maxx = max(maxx, tab[0]);
        for (int i=1; i<n; ++i){
            tab[i] = tab[i-1];
            s[i] == '0' ? tab[i]++ : tab[i]--;
            minn = min(minn, tab[i]);
            maxx = max(maxx, tab[i]);
        }
        int cnt = tab[n-1];
        for (int i=0; i<n; ++i){
            mp[tab[i]]++;
        }


        //cout << minn << ' ' << maxx << ' ' << cnt << endl;

        if (cnt == 0){ // dobrze
            if (mp[x] != 0) cout << -1 << endl;
            else cout << res << endl;
            continue;
        }

        if (x < minn){
            cout << 0 << endl;
            continue;
        }

        int L = (x - maxx)/cnt;
        int R = (x - minn)/cnt;
        L = max(L, 0);
        R = max(R, 0);

        while (L <= R){
            res += mp[x - cnt*L];
            ++L;
        }

        cout << res << endl;
    }
}

 
