#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    char tab[26][26];
    for (int i=0; i<26; i++)
        for (int j=0; j<26; j++)
            tab[i][j]=((i+j)%26)+65;
    string key, txt; int t, xd, l;
    cin >> t;
    while (t--)
    {
        cin >> key;
        cin.ignore();
        getline(cin, txt);
        xd=0;
        l=key.length();
        for (int i=0; i<txt.length(); i++)
        {
            if (txt[i]==' ') {cout << ' '; xd++;}
            else cout << tab[txt[i]-65][key[(i-xd)%l]-65];
        }
        cout << "\n";
    }
}
