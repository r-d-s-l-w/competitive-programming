#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, m;
    cin >> a >> b >> c;
    m=(max(max(a,b),c));
    if (a+b+c-m>m) cout << 0;
    else cout << (m+1)-(a+b+c-m);
}
