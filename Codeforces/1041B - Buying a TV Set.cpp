#include <bits/stdc++.h>
 
using namespace std;
 
unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
    return b == 0 ? a : gcd(b, a % b);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long long int a, b, x, y, div, value;
    cin >> a >> b >> x >> y;
    div = gcd(x, y);
    x /= div;
    y /= div;
    value = min(a/x, b/y);
    cout << value;
}
