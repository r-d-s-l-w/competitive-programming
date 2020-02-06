#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
int cost, len;
char s[1000100], t[1000100];
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> len >> s >> t;
    int i = 0;
    while (i < len){
        if (s[i] != t[i] && s[i+1] != t[i+1] && s[i] != s[i+1]) {
            ++cost;
            i += 2;
        }
        else{
            if (s[i] != t[i]) ++cost;
            ++i;
        }
    }
    cout << cost << endl;
}
