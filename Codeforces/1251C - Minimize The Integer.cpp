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

int n, t;
string s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){
        cin >> s;
        deque<int> a,b;
        for (int i=0; i<s.length(); ++i){
            if (s[i]%2) a.PB(s[i]-48);
            else b.PB(s[i]-48);
        }
        while (!a.empty() && !b.empty()){
            if (a.front() < b.front()) {
                cout << a.front();
                a.pop_front();
            }
            else {
                cout << b.front();
                b.pop_front();
            }
        }
        while (!a.empty()){
            cout << a.front();
            a.pop_front();
        }
        while (!b.empty()){
            cout << b.front();
            b.pop_front();
        }
        cout << endl;
    }

}
