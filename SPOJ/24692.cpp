#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string txt; cin >> txt;
    for (int i=0; i<txt.length(); i+=2)
    {
        if (txt[i]!='1') cout << char((txt[i]-48)*10+txt[i+1]-48);
        else {cout << char((txt[i+1]-48)*10+txt[i+2]+52); i++;}
    }
}
