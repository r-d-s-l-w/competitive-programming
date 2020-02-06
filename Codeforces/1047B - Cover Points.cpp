#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long long int a=0, x, y, n;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        if (x+y>a) a=x+y;
    }
    cout << a;
}
