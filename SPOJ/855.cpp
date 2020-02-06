#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
    int t, l, xd, j, H; string x, y, txt;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        txt=x+'#'+y+y; l=x.length(); H=0;
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
                if (tab[i]==l) H++;
            if (H>0) cout << "yes\n";
            else cout << "no\n";
    }
    return 0;
}
