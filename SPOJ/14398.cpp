#include <iostream>

using namespace std;

int main()
{
    int t, n, waga; string x, id[2];
    cin >> t;
    while (t--)
    {
        cin >> x;
        if (x=="g"||x=="gw") cout << "graph{" << endl;
        else cout << "digraph{" << endl;
        cin >> n;
        if (x=="g"||x=="d")
        {
        while (n--)
        {
            cin >> id[0] >> id[1];
        if (x=="g") cout << id[0] << " -- " << id[1] << ";" << endl;
        else  cout << id[0] << " -> " << id[1] << ";" << endl;
        }}
        else{
            while (n--)
            {
                cin >> id[0] >> id[1] >> waga;
                if (x=="gw") cout << id[0] << " -- " << id[1] << " [label = " << waga << "];" << endl;
                else if (x=="dw") cout << id[0] << " -> " << id[1] << " [label = " << waga << "];" << endl;
            }
        }
        cout << "}" << endl;
    }
    return 0;
}
