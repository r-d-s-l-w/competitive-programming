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
 
struct color{
    ll wartosc;
    ll L;
    ll R;
};
 
vector<color> col[200100];
ll n, m, q, T;
 
ll value(ll x, ll a){
    ll sz = col[a].size();
    if (x < col[a][0].wartosc){
        //cout << 1111 << endl;
        //cout << col[a][sz-1].L << endl;
        return col[a][sz-1].L + sz * (col[a][0].wartosc - x);
    }
    if (x > col[a][sz-1].wartosc){
        //cout << 2222 << endl;
        return col[a][0].R + sz * (x - col[a][sz-1].wartosc);
    }
    ll l_ptr = 0, r_ptr = sz-1;
    //cout << 3333 << endl;
    while (r_ptr - l_ptr > 0){
        ll mid = (r_ptr + l_ptr) / 2;
        if (col[a][mid].wartosc < x)
            l_ptr = mid + 1;
        else r_ptr = mid;
    }
    ll ptr = l_ptr;
    //cout << "    " << ptr << endl;
    return col[a][sz-1].L - col[a][ptr-1].L - (x - col[a][0].wartosc)*(sz-ptr)
    + col[a][0].R - col[a][ptr].R - ptr*(col[a][sz-1].wartosc - x);
}
 
ll sol(ll a, ll b){
    ll res = 0; ll temp = a;
    if (col[a].size() > col[b].size()){
        a = b; b = temp;
    }
    for (int i=0; i<col[a].size(); ++i){
        res += value(col[a][i].wartosc,b);
        //cout << "     " << res << endl;
    }
 
    return res;
}
 
void precompute(){
    for (int i=0; i<=m; ++i){
        for (int j=0; j<col[i].size(); ++j){
            if (j!=0) col[i][j].L = col[i][j-1].L + (col[i][j].wartosc - col[i][0].wartosc);
            else col[i][j].L = 0;
        }
        ll temp =  col[i].size() - 1;
        for (int j=temp; j>=0; --j){
            if (j!=temp) col[i][j].R = col[i][j+1].R + (col[i][temp].wartosc - col[i][j].wartosc);
            else col[i][j].R = 0;
        }
        /// 1 DEBUG - OK
        /*
        cout << "    " << i << endl;
        for (int j=0; j<col[i].size(); ++j){
            cout << "    " << j << ' ' << col[i][j].wartosc << ' ' <<
            col[i][j].L << ' ' << col[i][j].R << endl;
        }
        cout << endl;
        */
    }
}
 
void ini(){
    for (int i=0; i<=m; ++i)
        col[i].clear();
    n = 0; m = 0; q = 0;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--){
        ini();
        ll x, a, b;
        cin >> n >> m >> q;
        for (int i=0; i<n; ++i){
            cin >> x;
            col[x].PB({i,0,0});
        }
        precompute();
        while (q--){
            cin >> a >> b;
            cout << sol(a,b) << endl;
        }
    }
    return 0;
}
