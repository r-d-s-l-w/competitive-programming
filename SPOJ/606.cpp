#include <iostream>

using namespace std;

int tab[100], t, n, x;

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j<n; j++)
        {
            cin >> tab[j];
        }
        for (int k=n-1; k>=0; k--)
        {
            cout << tab[k] << " ";
        }
    }

    return 0;
}
