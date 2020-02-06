#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, k, x, first, last, xd;
    vector <int> tab;
    cin >> t;
    while (t--)
    {
        cin >> n >> k; first=0; last=n-1; xd=0;
        while (n--)
        {
            cin >> x;
            tab.push_back(x);
        }
        sort(tab.begin(),tab.end());
        while(last-first>=0)
        {
            if (tab[last]+tab[first]<=k) {xd++; last-=1; first+=1;}
            else {xd++; last-=1;}
        }
        cout << xd << endl;
        tab.erase(tab.begin(),tab.end());
    }
}
