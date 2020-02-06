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
 
int n, res, x;
vi a, b;
bool fined[100100];
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> x;
        a.PB(x);
    }
    for (int i=0; i<n; ++i){
        cin >> x;
        b.PB(x);
    }
    reverse(ALL(a));
    reverse(ALL(b));
    while(b.size() > 0 && a.size() > 0){
        if (fined[a.back()] == 1)
            a.pop_back();
 
        else if (b.back() != a.back()){
            fined[b.back()] = 1;
            ++res;
            //cout << a.back() << ' ' << b.back()  << endl;
            b.pop_back();
        }
        else {
            a.pop_back();
            b.pop_back();
        }
    }
    cout << res << endl;
 
}
