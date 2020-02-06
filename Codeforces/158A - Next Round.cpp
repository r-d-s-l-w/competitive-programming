#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    int k, n, arr[105];
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> arr[i];
    if (arr[k-1]==0){
        int x=0;
        while (arr[x]>0) ++x;
        cout << x;
    }
    else {
        int x=0;
        while (arr[x]>=arr[k-1]&&x<n) ++x;
        cout << x;
    }
}
