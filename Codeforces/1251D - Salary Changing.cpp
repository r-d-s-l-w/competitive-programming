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

ll n, t, c;
int INF = 2e9;

int ile_potrzebuje[200200];
pi tab[200200];
vector<pi> ile_mozemy;

bool mozemy(int val){
    ll pieniadze = c;
    int mid = n/2;
    if (ile_mozemy[mid].F < val)
        return 0;

    for (int i=0; i<n; ++i){
        if (tab[i].S < val) ile_potrzebuje[i] = INF;
        else ile_potrzebuje[i] = max(val - tab[i].F,0);
    }

    ll tmp = 0;
    sort(ile_potrzebuje,ile_potrzebuje+n);
    for (int i=0; i<=mid; ++i){
        tmp += ile_potrzebuje[i];
    }
    if (pieniadze - tmp < 0) return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> c;

        for (int i=0; i<n; ++i){
            int x, y;
            cin >> tab[i].F >> tab[i].S;
            c -= tab[i].F;
            ile_mozemy.push_back({tab[i].S,i});
        }
        sort(ile_mozemy.rbegin(),ile_mozemy.rend());

        int L = 1, R = 1e9;
        while (L < R){
            int mid = (L+R+1)/2;
            if (mozemy(mid)) L = mid;
            else R = mid - 1;
            //cout << L << ' ' << R << endl;
        }

        cout << L << endl;

        ile_mozemy.clear();
    }

}
