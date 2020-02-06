#include <bits/stdc++.h>

using namespace std;

vector <long long int> tab;

int main()
{
    ios_base::sync_with_stdio(0);
    long long int k, x, y, kontrola = 0, mini = 1000000, maks = 0, wynik = 1;
    cin >> k;
    while (k--)
    {
        cin >> x >> y;
        tab.push_back(y);
        if (y < mini) mini = y;
        else if (y > maks) maks = y;
    }
    tab.push_back(-1);
    while (kontrola < tab.size())
    {
        kontrola = 0;
        for (int i=0; i<tab.size(); i++)
        {
            if (tab[i] - mini > 0)
            {
                int xd = tab[i] - mini;
                int lol = 1;
                while (tab[i+1] - mini > 0)
                {
                    i++; lol++;
                    if (tab[i] - mini < xd) xd = tab[i] - mini;
                }
                for (int j = i; j > i - lol; j--) tab[j] -= xd;
                wynik++;
            }
            else kontrola++;
        }
    }
    cout << wynik;
}
