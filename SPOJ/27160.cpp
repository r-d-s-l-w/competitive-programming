#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string txt; int k, xd;
    cin >> k;
    while (k--)
    {
        cin >> txt;
        for (int i=0; i<txt.length(); i+=5)
        {
            xd=0;
            if (txt[i]=='1') xd+=16;
            if (txt[i+1]=='1') xd+=8;
            if (txt[i+2]=='1') xd+=4;
            if (txt[i+3]=='1') xd+=2;
            if (txt[i+4]=='1') xd++;
            cout << char(65+xd);
        }
        cout << endl;
    }
}
