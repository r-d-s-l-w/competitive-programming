#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    double n, p, xd; int q, a, b, m;
    cin >> n >> m >> p;
    p*=m; char x[m];
    vector <int> tab(n+2,0);
    for (int i=1; i<=n; i++)
    {
        xd=0;
        for (int j=0; j<m; j++)
            {cin >> x[j]; xd+=x[j]-48;}
        if (xd>p) tab[i]+=1; tab[i+1]=tab[i];
    }
    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        cout << tab[b]-tab[a-1] << endl;
    }
}
