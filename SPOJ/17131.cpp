#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int d, n, x; bool xd;
    cin >> d;
    while (d--)
    {
        cin >> n;
        x=1; xd=true;
        vector <int> tab(n, 0);
        while (x!=n)
        {
            for (int i=0; i<n; i++)
            if (tab[i]==0&&xd==true) {tab[i]=x; x++; xd=false;}
            else if (tab[i]==0) xd=true;
        }
        for (int i=0; i<n; i++) if (tab[i]!=0) cout << tab[i] << " "; else cout << n << " ";
        cout << endl;
    }

}
