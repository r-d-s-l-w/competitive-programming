#include <bits/stdc++.h>

using namespace std;

struct uczen
{
    int nr;
    long long int wiek;
};

bool xd (uczen x, uczen y)
{
    if (x.wiek > y.wiek) return 0;
    else if (x.wiek < y.wiek) return 1;
    else if (x.nr > y.nr) return 0;
    else return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    vector <uczen> tab;
    int d, n, nr; string data; uczen x;
    cin >> d;
    while (d--)
    {
        cin >> n;
        for (int i=0; i<n; i++)
        {
            cin >> nr >> data;
            x.nr = nr;
            x.wiek = (data[0] - 48) * 10000000 + (data[1] - 48) * 1000000 + (data[2] - 48) * 100000 + (data[3] - 48) * 10000 + (data[5] - 48) * 1000 + (data[6] - 48) * 100 + (data[8] - 48) * 10 + (data[9] - 48);
            tab.push_back(x);
        }
        sort (tab.begin(), tab.end(), xd);
        for (int i=0; i<tab.size(); i++)
            cout << tab[i].nr << " "; cout << endl;
        tab.clear();
    }
}
