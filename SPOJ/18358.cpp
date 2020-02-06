#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string txt; double suma=0, x, tab[26]={0};
    getline(cin, txt);
    for (int i=0; i<txt.length(); i++)
        if (txt[i]!=' ') {tab[txt[i]-65]++; suma++;}
    for (int i=0; i<26; i++)
    {
        cout << char(i+65);
        x=round((tab[i]/suma)*100);
        while(x--) cout << '*'; cout << "\n";
    }
    return 0;
}
