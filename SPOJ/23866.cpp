#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, k, wynik, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> k; long long int wynik=0; int tab[n];
        for (int i=0; i<n; i++) cin >> tab[i];
        sort(tab, tab+n);
        for (int i=n-k; i>=0; i-=k)
            wynik+=tab[i];
        cout << wynik << "\n";
    }
}
