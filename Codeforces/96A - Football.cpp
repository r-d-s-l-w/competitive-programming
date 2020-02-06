#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
constexpr int INF = 1e9 + 1;
 
char s[1000];
int tmp = 1;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    int i = 1;
    while (s[i] != 0){
        if (s[i] == s[i-1]) ++tmp;
        else tmp = 1;
        if (tmp > 6){
            cout << "YES" << endl;
            return 0;
        }
        ++i;
    }
    cout << "NO" << endl;
}
