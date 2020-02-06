#include <iostream>
using namespace std;

int main()
{
    int k, n;
    cin >> n >> k;
    int x[n];
    for(int i=0; i<n; i++) cin>>x[i];
    for(int i=k; i<n; i++) cout<<x[i]<<" ";
    for(int i=0; i<k; i++) cout<<x[i]<<" ";
    return 0;
}
