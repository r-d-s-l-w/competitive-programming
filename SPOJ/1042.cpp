#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int tab[m*n];
    for(int i=0; i<m*n; i++) cin>>tab[i];
    for(int j=0; j<n; j++){for(int i=0; i<m*n; i++) if(i%n==j)cout<<tab[i]<<" "; cout << endl;}
    return 0;
}
