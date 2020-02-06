#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
constexpr int INF = 1e9 + 1;
 
char s[100100];
int len;
int one[2], two[2];
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s; one[0] = two[0] = INF;
    while (s[len] != 0) ++len;
    int i = 0;
    while (i < len){
        if (s[i] == 'A' && s[i+1] == 'B'){
            one[0] = min(one[0],i);
            one[1] = max(one[1],i);
        }
        else if (s[i] == 'B' && s[i+1] == 'A'){
            two[0] = min(two[0],i);
            two[1] = max(two[1],i);
        }
        ++i;
    }
    if (one[0] != INF && two[0] != INF){
        if (two[1] - one[0] > 1) cout << "YES" << endl;
        else if (one[1] - two[0] > 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else cout << "NO" << endl;
 
}
