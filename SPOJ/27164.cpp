#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int lcm (int a, int b)
{
    int temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, tab[100];
    cin >> n;
    for (int i=0; i<n; i++) cin >> tab[i];
    int result = accumulate (tab, tab + n, 1, lcm);
    cout << result;
}
