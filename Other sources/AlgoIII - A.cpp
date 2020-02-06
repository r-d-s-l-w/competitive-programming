/// Radoslaw Mysliwiec 2019
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB emplace_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
int z, h, n, tab[1000100];
 
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20);
 
    cin >> z;
    while(z--){
        cin >> h >> n;
        for(int i=0; i<n; ++i)
            cin >> tab[i];
 
        sort(tab,tab+n);
 
        int L = 0, R = n - 1, res = 0;
 
        while (L <= R){
            if (tab[R] + tab[L] <= h){
                --R; ++L;
            }
            else --R;
            ++res;
        }
        cout << res << endl;
    }
 
 
}
