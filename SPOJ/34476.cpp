#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string txt;
    cin >> txt;
    for(int i=0; i<txt.length(); i+=2)
    {
        cout << (char)((txt[i+1]+txt[i])%26+'A');
    }
}
