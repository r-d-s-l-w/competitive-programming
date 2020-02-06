#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int k, a, b, tab[1001][1001]; string X, Y;
    for(int i=0; i<=1000; i++)
    {
        tab[i][0]=0;
        tab[0][i]=0;
    }
    cin >> k;
    while (k--)
    {
        cin >> a >> X >> b >> Y;
        for (int y=1; y<=b; y++)
        for (int x=1; x<=a; x++)
        {
            if (X[x-1]==Y[y-1]) tab[x][y]=tab[x-1][y-1]+1;
            else tab[x][y]=max(tab[x-1][y],tab[x][y-1]);
        }
        cout << tab[a][b] << endl;
    }
    return 0;
}
