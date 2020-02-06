#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, x, a, suma; char znak;
    vector <char> tab;
    vector <char> xd;
    cin >> n;
    while (n--)
    {
        suma=0; a=1;
        while (cin >> x >> znak)
        {
            if (x%2==0) tab.push_back('0');
            else tab.push_back('1');
            tab.push_back(znak);
            if (znak=='=') break;
        }
        for (int i=1; i<tab.size(); i++)
        {
            if (tab[i]=='*') a*=((tab[i-1]-48)*(tab[i+1]-48));
            else if (tab[i]=='+'||tab[i]=='-'||tab[i]=='=') {if (a==1) suma+=tab[i-1]-48; a=1;}
        }
        if (suma%2==0) cout << "TAK\n";
        else cout << "NIE\n";
        tab.erase(tab.begin(),tab.end());
    }
}
