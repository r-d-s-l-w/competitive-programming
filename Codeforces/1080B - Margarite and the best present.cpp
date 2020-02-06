#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long q, l , r;
    cin >> q;
    while (q--){
        cin >> l >> r;
        if (l == r) l%2==0?cout<<l<< "\n":cout<<-l<< "\n";
        else if (l%2==1 && r%2==1) cout << - r + (r - l)/2<< "\n";
        else if (l%2==1 && r%2==0) cout << (r - l + 1) / 2<< "\n";
        else if (l%2==0 && r%2==0) cout << r - (r - l)/2<< "\n";
        else cout << (l - r - 1) / 2 << "\n";
    }
}
