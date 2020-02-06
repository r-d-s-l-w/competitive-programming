#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string txt; int xd;
    getline(cin, txt);
    for (int i=0; i<txt.length(); i+=2)
        {cout << txt[i]; xd=i;}
    xd==txt.length()-1?xd-=1:xd+=1;
    for (int i=xd; i>0; i-=2)
        cout << txt[i];
}
