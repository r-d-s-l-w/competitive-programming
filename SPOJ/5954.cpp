#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int Z, n; string txt;
    cin >> Z;
    while (Z--)
    {
        cin >> n;
        vector<string> tab; vector <int> TAB; int maks=0; vector <int> length;
        for (int k=0; k<n; k++)
        {
            int x=0, n=0, l;
            cin >> txt;
            l=txt.length();
            sort(txt.begin(),txt.end());
            tab.push_back(txt); TAB.push_back(1); length.push_back(txt.length());
            for (int i=k-1; i>=0; i--)
            {
                if (length[i]==length[k]) if(tab[i]==tab[k]) {TAB[k]+=TAB[i]; if (maks<TAB[k]) maks=TAB[k]; break;}
            }
        }
    cout << maks << "\n";
    }
    return 0;
}
