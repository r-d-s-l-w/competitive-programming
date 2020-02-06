#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        long long a, b;
        float m;
        cin >> a >> b >> m;
        if (m > 1 || m < -1) cout << 0 << "\n";
        else {
            if (a > b) cout << 0 << "\n";
            else if (m == 1){
                if (a % 2 == 0) cout << ((b - a + 1) / 2) << "\n";
                else cout << ((b - a) / 2) << "\n";
            }
            else if (m == -1){
                if (a % 2 == 0) cout << ((b - a) / 2) << "\n";
                else cout << ((b - a + 1) / 2) << "\n";
            }
            else if (m == 0) {
                cout << b - a + 1 << "\n";
            }
            else if (m > 0){
                if (a % 2 == 0) cout << ((b - a + 1) / 2) * 2 << "\n";
                else cout << ((b - a) / 2) * 2 << "\n";
            }
            else if (m < 0){
                if (a % 2 == 0) cout << ((b - a) / 2) * 2 << "\n";
                else cout << ((b - a + 1) / 2) * 2 << "\n";
            }
        }
    }
}
