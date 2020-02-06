#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    int n, a, b, c, m;
    cin >> n;
    if (n==3) cout << 1 << ' ' << 1 << ' ' << 1;
    else if (n%3!=0) cout << 1 << ' ' << 2 << ' ' << n-3;
    else cout << 1 << ' ' << 1 << ' ' << n-2;
}
