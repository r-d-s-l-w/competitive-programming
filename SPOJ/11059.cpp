#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t, m, x;
    cin >> t;
    while (t--)
    {
        vector <int> tab;
        long long int sufiks=0, prefiks=0; int xd=0;
        cin >> m;
        while (m--)
        {
            cin >> x;
            tab.push_back(x);
            sufiks+=x;
        }
        for (int i=0; i<tab.size(); i++)
        {
            if (prefiks==sufiks&&i!=0) {cout << i << endl; xd=1; break;}
            else {prefiks+=tab[i]; sufiks-=tab[i];}
        }
        if (xd==0) cout << 0 << endl;
    }
    return 0;
}
