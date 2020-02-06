#include <iostream>
using namespace std;

int main()
{
    long long int u, s, d, tab[64], TAB[64], n;
    while (cin >> u >> s >> d)
    {
        int i=0;
        if (u==0&&s==0&&d==0) break;
        while (s) {tab[i++]=s%2; s/=2;}
        for(int j=0;j<i;j++)
        {
            n=u%d;
            TAB[j]=n;
            u=n*n;
        }
        u=1;
        for(int j=0;j<i;j++)
        if (tab[j]==1) u=(u*TAB[j])%d;
        cout << u%d << endl;
    }
    return 0;
}
