#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int q, n, k;
    cin >> q;
    while (q--)
    {
       cin >> n >> k;
       if (n%2==1) cout << "BRAK\n";
       else if (k*2==n) cout << n << "\n";
       else cout << (k+(n/2))%n << "\n";
    }
    return 0;
}
