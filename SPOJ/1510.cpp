#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, l, xd, j; string x, y, txt;
    cin >> t;
    while (t--)
    {
        cin>>txt;
        xd=txt.length();
        int tab[xd]; tab[0]=0;
        j=0;
        for(int i=1; i<xd; i++)
        {
            while(j>0&&txt[j]!=txt[i]) j=tab[j-1];
            if (txt[j]==txt[i]) j++;
            tab[i]=j;
        }
        for (int i=0; i<xd; i++)
            cout << tab[i] << " "; cout << "\n";
    }
    return 0;
}
