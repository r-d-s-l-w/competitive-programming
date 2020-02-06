/// Radoslaw Mysliwiec 2020
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
#define dd cout << " debug";
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;
 
const int INF = 1e9 + 1;
int n, k;
vi tab;
 
int check(ll x){
    int res = 0, i = 0;
    while(i < n){
        ll tmp = 0;
        if (tab[i] > x) return INF;
        while (tmp + tab[i] <= x && i < n){
            tmp += tab[i];
            ++i;
        }
        ++res;
    } return res;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> k;
    tab.resize(n);
    for (int i=0; i<n; ++i)
        cin >> tab[i];
 
    ll L = 1, R = 1e16;
    while (L < R){
        ll mid = (L + R)/2;
        if (check(mid) > k) L = mid + 1;
        else R = mid;
    } cout << L << endl;
}
