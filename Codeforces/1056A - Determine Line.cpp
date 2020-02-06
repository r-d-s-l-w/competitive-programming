#include <bits/stdc++.h>
 
using namespace std;
 
int tab[101];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, n, x, a;
    cin >> n;
    a=n;
    while (n--){
        cin >> r;
        for (int i = 0; i < r; ++i){
            cin >> x;
            tab[x]++;
        }
    }
 
    for (int i=0; i<101; ++i) if (tab[i]==a) cout << i << ' ';
 
}
