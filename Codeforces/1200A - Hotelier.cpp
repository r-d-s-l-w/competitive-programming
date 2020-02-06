// Radoslaw Mysliwiec 2019
#pragma GCC optimize("O3")
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
using matrix = vector<vll>;
 
bool tab[10];
char s[100100];
int n;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> s;
    for (int i=0;i<n;++i){
        if (s[i] == 'L'){
            for (int j=0; j<10; ++j)
            if (tab[j] != 1) {
                tab[j] = 1;
                break;
            }
        }
        else if (s[i] == 'R'){
            for (int j=9; j>=0; --j)
            if (tab[j] != 1) {
                tab[j] = 1;
                break;
            }
        }
        else tab[s[i]-48] = 0;
    }
    for (int i=0; i<10; ++i)
        cout << tab[i];
 
    return 0;
}
