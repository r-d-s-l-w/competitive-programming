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
int res;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s + 1; s[0] = 'a';
    int i = 1;
    while (s[i] != 0){
        res += min(max(s[i-1], s[i]) - min(s[i-1], s[i]), min(s[i-1], s[i]) - max(s[i-1], s[i]) + 26);
        ++i;
    }
    cout << res << endl;
}
