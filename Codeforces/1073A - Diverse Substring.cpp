#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
constexpr int INF = 1e9 + 1;
 
char s[1001];
int len, l, r, tmp, minn = INF;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> len >> s;
    for (int i=0; i<len-1; ++i){
        if (s[i] != s[i+1]) {
            cout << "YES" << endl << s[i] << s[i+1] << endl; return 0;
        }
    }
    cout << "NO" << endl;
}
