#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long long int d, n;
    cin >> d;
    while (d--)
    {
        cin >> n;
        for (int i=sqrt(n); i>0; i--)
        {
            if (n%i==0) {cout << 2*i+2*n/i << "\n"; break;}
        }
    }
}
