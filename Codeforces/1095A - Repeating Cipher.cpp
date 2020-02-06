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
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;
 
constexpr int MOD = 1;
constexpr int INPUT =  + 100;
constexpr int INF = 1e9 + 1;
constexpr double EPS = 1e-9;
 
ll tab[INPUT];
vi arr;
ll l;
string s;
 
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.setf(ios::fixed); cout.precision(20);
    //freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    cin >> l;
    cin >> s;
    int i = 0, j = 1;
    while(i < l){
        cout << s[i];
        i+=j;
        j++;
    }
 
}
