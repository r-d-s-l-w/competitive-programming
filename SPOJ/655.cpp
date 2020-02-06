#include <iostream>

using namespace std;

void gray(int n, int *tab, int k, char direction)
{
    if (n==k)
    {
        for (int i=0; i<k; i++) cout << tab[i];
        cout << "\n";
    }
    else
    {
        if (direction==1) tab[k]=0;
        else tab[k]=1;
        gray(n, tab, k+1, 1);
        if (direction==1) tab[k]=1;
        else tab[k]=0;
        gray(n, tab, k+1, 0);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, tab[13];
    cin >> t;
    while (t--)
    {
        cin >> n;
        gray(n, tab, 0, 1);
    }
    return 0;
}
