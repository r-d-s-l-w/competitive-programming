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
 
queue<int> arr;
ll a, b;
bool tab[32];
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.setf(ios::fixed); cout.precision(20);
    //freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    cin >> a >> b;
    if (b > a) {cout << "NO"; return 0;}
    int i = 0;
    while (a != 0){
        if (a%2==1)
            tab[i] = 1;
        ++i;
        a/=2;
    }
    ll ctr = 0;
    for (int i=0; i<31; ++i){
        if (tab[i] == 1){
            ctr++;
            ll x = 1;
            for (int j=0; j<i; ++j)
                x*=2;
            arr.push(x);
        }
    }
    if (b < ctr) cout << "NO";
    else {
        while (arr.size()<b){
 
                if (arr.front()%2 == 0){
                    arr.push(arr.front()/2);
                    arr.push(arr.front()/2);
                    arr.pop();
                }
                else {
                    arr.push(arr.front());
                    arr.pop();
                }
        }
        cout << "YES\n";
        while(!arr.empty()){
		cout<<arr.front() << ' ';
		arr.pop();
	}
    }
 
 
}
