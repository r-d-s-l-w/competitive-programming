#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    int n, x; bool xd=false;
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (x) xd=true;
    }
    if (xd) cout << "HARD";
    else cout << "EASY";
}
