/// Radoslaw Mysliwiec 2019
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

int n, m;
int monster[200200];
int st[400400];
pi hero[200200];

void build() {
    for (int i=0; i<n; ++i)
        st[i+n] = hero[i].S;

    for (int i = n - 1; i > 0; --i)
        st[i] = max(st[i<<1],st[i<<1|1]);
}

int query(int l, int r) {
    int res = -1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res,st[l++]);
        if (r&1) res = max(res,st[--r]);
    }
    return res;
}

bool can(int l, int r, int maks){
    int L = 0, R = n;
    //int maks = query(l,r+1);
    while (L < R){
        int mid = (L+R)/2;
        if (hero[mid].F >= r-l+1) R = mid;
        else L = mid + 1;
    }
    //cout <<
    if (query(L,n) >= maks) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cases;
    cin >> cases;
    while (cases--){
        cin >> m;
        for (int i=0; i<m; ++i){
            cin >> monster[i];
        }
        cin >> n;
        for (int i=0; i<n; ++i){
            cin >> hero[i].S >> hero[i].F;
        }
        sort(hero,hero+n);
        //for (int i=0; i<n; ++i)
           // cout << hero[i].F << ' ' << hero[i].S << endl;
        bool dobrze = 1;
        int res = 0;
        build();
        //cout << "    " << query(1,2) << endl;
        int it = 0;
        while(it < m){
            int lastit = it;
            int tmp = it;
            int maks = monster[it];
            while(it < m && can(tmp,it,maks)){
                ++it;
                maks = max(maks,monster[it]);
                //cout << "   " << it << endl;
            }
            //cout << "     " << it << endl;
            ++res;
            if (lastit == it) {
                dobrze = 0;
                break;
            }
        }
        if (dobrze) cout << res << endl;
        else cout << -1 << endl;
    }

}
