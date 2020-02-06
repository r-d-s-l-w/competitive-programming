#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, x; vector <bool> tab(1000001, false);
    for (int i=0; i<1001; i++)
        tab[i*i]=true;
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (x>0&&tab[x]==true) cout << "TAK" << endl << endl;
        else cout << "NIE" << endl << endl;
    }

    return 0;
}
