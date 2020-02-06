#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t, x;
    cin >> t;
    while (t--){
        cin >> x;
        if (x & 1 == 0) cout << x/2 << ' ' << x/2 << "\n";
        else if (__builtin_popcount(x) % 2 == 0) cout << x / 2 << ' ' << (x + 1) / 2 << "\n";
        else cout << (x + 1)/ 2 << ' ' << x / 2 << "\n";
    }
}
