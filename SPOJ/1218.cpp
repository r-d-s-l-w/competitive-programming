#include <iostream>

using namespace std;

int main()
{
    int t, l, xd, j; string x, y, txt;
    cin >> t;
    while (t--)
    {
        cin >> l >> x >> y;
        if (l<=y.length())
        {
            txt=x+'#'+y;
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
                if (tab[i]==l) cout << i-2*l << endl;
        }
    }
    return 0;
}
