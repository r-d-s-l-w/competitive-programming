#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int z, n, x, xd;
    cin >> z;
    while (z--)
    {
        vector <int> tab;
        cin >> n;
        while (n--)
        {
            cin >> x;
            tab.push_back(x);
        }
        for (int i=0; i<tab.size()-1; i++) {xd=tab[i]^tab[i+1]; tab[i+1]=xd;}
        if (xd==0) cout << "2" << endl;
        else cout << "1" << endl;

    }
    return 0;
}
