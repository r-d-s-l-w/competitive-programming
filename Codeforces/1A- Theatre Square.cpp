#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long long int n, m, a, x=0, y=0;
    cin >> n >> m >> a;
    if (n%a != 0) x++;
    if (m%a != 0) y++;
    x+=n/a;
    y+=m/a;
    cout << x*y;
}
