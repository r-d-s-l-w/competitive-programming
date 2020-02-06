#include <iostream>
#include <string>

using namespace std;

int main()
{
    string txt; char tab[100]; int l, xd, x;
    while(getline(cin, txt))
    {
        l=txt.length(); x=0;
        for (int i=0; i<l; i++)
        {
            if (txt[i]==' ') {xd=i; break;}
            else tab[i]=txt[i];
        }
        cout << tab[x]; x++;
        for (int i=xd+1; i<l; i++)
        {
            if (txt[i]==' ') {cout << " " << tab[x]; x++;}
            else cout << txt[i];
        }
        cout << endl;
    }
}
