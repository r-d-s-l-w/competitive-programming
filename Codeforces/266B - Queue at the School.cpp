#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
char s[100];
int len, t;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> len >> t;
    cin >> s;
    int k = 0;
    while (k < t){
        int i = 0;
        while (i < len){
            if (s[i] == 'B' && s[i+1] == 'G') {
                s[i] = 'G'; s[i+1] = 'B';
                ++i;
            }
            ++i;
        }
        ++k;
    }
    cout << s << endl;
}
