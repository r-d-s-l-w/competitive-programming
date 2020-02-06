#include <iostream>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int tab[n], maks=0, indeks=0;
        for (int i=0; i<n; i++) cin >> tab[i];
        for (int i=0; i<n; i++){ int x=0;
        for (int j=0; j<n; j++)
        {
            if(tab[(j+i)%n]==j+1) x++;
        } if (x>maks) {maks=x; indeks=i;}}
        for (int i=indeks; i<n+indeks; i++)
        cout << tab[i%n] << " "; cout << endl;
    }
    return 0;
}
