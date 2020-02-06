#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int tab[100], x=25, y=0, wynik=0;
    for (int i=0; i<26; i++) cin >> tab[i];
    sort(tab, tab+26);
    for (int i=52; i>0; i--)
    {
        if (tab[x]==i) {y++; x--;}
        else if (tab[x]!=i&&y!=0) {y--; wynik++;}
    }
    cout << wynik << endl;
    return 0;
}
