#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--){
    int k,l;
    cin>>l>>k;
    int tab[k][l];
    for(int x=0;x<l;x++)
    {
        for(int y=0;y<k;y++)
        {
            cin >> tab[y][x];
        }
    }
    for(int i=1;i<k;i++) cout<<tab[i][0]<<" "; cout << tab[k-1][1] << endl;
    for(int i=1;i<l-1; i++) {cout<<tab[0][i-1]<<" "; for(int j=1; j<k-1;j++)cout<<tab[j][i]<<" "; cout << tab[k-1][i+1] << endl;}
    cout << tab[0][l-2] << " "; for(int i=0; i<k-1; i++) cout << tab[i][l-1] << " "; cout << endl;
    }
    return 0;
}
