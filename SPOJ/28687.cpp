#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string txt; int x=0;
    while (getline(cin, txt))
    {
        for(int i=0; i<txt.length(); i++)
        {
            if (txt[i]=='?'||txt[i]=='!') x++;
            else if (txt[i]=='.'&&i<txt.length()-1&&txt[i+1]=='.') {x++; i+=2;}
            else if (txt[i]=='.') x++;
        }
    }
    cout << x;
}
