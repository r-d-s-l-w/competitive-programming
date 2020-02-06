#include <iostream>
using namespace std;

int main()
{
    int k;
    string txt;
    cin >> k;
    while (k--)
    {
        int x=0, y=0, n=0, lvl;
        cin >> lvl;
        cin >> txt;
        for(int i=0; i<txt.length(); ++i)
        {
            if(txt[i]=='U') n++; else n--;
            if(n<y) y=n;
            if(n>x) x=n;
        }
    if(x-y+1>lvl) cout << "NIE\n"; else cout << "TAK\n";
    }
}
