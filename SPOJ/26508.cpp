#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int d, n, a;
    cin >> d;
    while (d--)
    {
        cin >> n; cin >> a; vector <int> tab(a, 1);
        for (int i=1; i<n; i++)
        {
            cin >> a;
            for (int j=0; j<a; j++) tab[j]++;
        }
        for (int i=0; i<tab.size(); i++) cout << tab[i] << " ";
        cout << "\n";
    }
}
