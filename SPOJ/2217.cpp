#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int x, y;
    while (cin>>x)
    {
        if (cin.peek()=='\n') cout << "-" << endl;
        else {
        vector<int> tab;
        while (cin>>y)
        {
        int xd=0;
        for (int i=0; i<tab.size(); i++)
        {
            if (tab[i]==y) {xd=1; break;}
        }
        if (xd!=1) tab.push_back(y);
        if (cin.peek()=='\n') break;
        }
        sort(tab.begin(), tab.end());
        if (x>tab.size()) cout << "-" << endl;
        else cout << tab[tab.size()-x] << endl;}
    }
    return 0;
}
