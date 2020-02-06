#include <iostream>

using namespace std;

int x, t, tab[100], n;
int main()
{
    cin >> t;
    for (int i = 0; i<t; i++)
    {
        cin >> n;
        for (int j = 0; j<n; j++)
        {
            cin >> tab[j];
        }
        for (int k = 1; k<n; k++)
        {
            cout << tab[k] << " ";
        }
        cout << tab[0] << endl;
    }
    return 0;
}
