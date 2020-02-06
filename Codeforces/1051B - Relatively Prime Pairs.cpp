#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long long int r, l;
    cin >> l >> r;
    cout << "YES";
    for (unsigned long long int i=l; i<r; i=i+2)
    {
        cout << "\n" << i << ' ' << i+1;
    }
}
