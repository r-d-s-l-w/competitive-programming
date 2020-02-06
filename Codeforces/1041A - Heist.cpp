#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    int n, a[2000], mini=1000000001, maks=-1;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin>> a[i];
        if (a[i] > maks) maks = a[i];
        if (a[i] < mini) mini = a[i];
    }
    cout << maks - mini - n + 1;
 
}
