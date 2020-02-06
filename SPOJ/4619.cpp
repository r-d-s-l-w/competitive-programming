#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string txt; int x=0, xd;
    while (getline(cin, txt))
    {
        for (int i=0; i<txt.length(); i++)
        {
            if (txt[i]=='<'&&txt[i+1]=='/')
            {
                x--; i+=2;
                while (txt[i]>='0'&&txt[i]<='9'||txt[i]>='a'&&txt[i]<='z'||txt[i]>='A'&&txt[i]<='Z') i++;
            }
            else if (txt[i]=='<')
            {
                for (int j=0; j<x; j++) cout << "    "; i++;
                while (txt[i]>='0'&&txt[i]<='9'||txt[i]>='a'&&txt[i]<='z'||txt[i]>='A'&&txt[i]<='Z') {cout << txt[i]; i++;}
                cout << ":\n"; x++;
            }
            if (txt[i]==' '&&txt[i+1]>='0'&&txt[i+1]<='9'||txt[i+1]>='a'&&txt[i+1]<='z'||txt[i+1]>='A'&&txt[i+1]<='Z')
            {
                for (int j=0; j<x; j++) cout << "    "; i++;
                while (txt[i]>='0'&&txt[i]<='9'||txt[i]>='a'&&txt[i]<='z'||txt[i]>='A'&&txt[i]<='Z') {cout << txt[i]; i++;}
                cout << " = "; i+=2;
                while (txt[i]>='0'&&txt[i]<='9'||txt[i]>='a'&&txt[i]<='z'||txt[i]>='A'&&txt[i]<='Z') {cout << txt[i]; i++;}
                cout << "\n";
            }
            if (txt[i]=='/'&&(txt[i+1]>='0'&&txt[i+1]<='9'||txt[i+1]>='a'&&txt[i+1]<='z'||txt[i+1]>='A'&&txt[i+1]<='Z'||txt[i+1]=='>'))
            {
                i++; x--;
                while (txt[i]>='0'&&txt[i]<='9'||txt[i]>='a'&&txt[i]<='z'||txt[i]>='A'&&txt[i]<='Z') i++;
            }
        }
    }
}
