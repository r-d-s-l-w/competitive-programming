#include <bits/stdc++.h>
 
using namespace std;
 
long long a, b;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t, n, d, x, y;
    cin >> t;
    while (t--){
        cin >> n >> x >> y >> d;
        if (y >= x && (y - x)%d == 0) cout << (y-x)/d << "\n";
        else if (y < x && (y - x)%d == 0) cout << (x-y)/d << "\n";
        else if ((y - 1)%d == 0 && (n - y)%d == 0) cout << min ((x+d-2)/d + (y-1)/d , (n-x + d - 1)/d + (n-y)/d) << "\n";
        else if ((y - 1)%d == 0) cout << (x+d - 2)/d + (y-1)/d << "\n";
        else if ((n - y)%d == 0) cout << (n-x + d - 1)/d + (n-y)/d << "\n";
        else cout << -1 << "\n";
    }
}
