#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string w, txt; int x, tab[26], wynik=0, wzor[26]; bool xd;
    cin >> w >> x;
    for (int i=0; i<26; i++) {tab[i]=0; wzor[i]=0;}
    for (int i=0; i<w.length(); i++)
        wzor[w[i]-97]++;
    while (x--)
    {
        cin >> txt; xd=true;
        for (int i=0; i<txt.length(); i++)
        tab[txt[i]-97]++;
        for (int i=0; i<26; i++)
            if (wzor[i]>tab[i]) {xd=false; break;}
        if (xd==true) wynik++;
        for (int i=0; i<26; i++) tab[i]=0;
    }
    cout << wynik;
}
