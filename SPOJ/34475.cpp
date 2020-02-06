#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int k; string txt;
    cin >> k;
    while (k--)
    {
        char a='Z', b='A';
        cin >> txt;
        for (int i=0; i<txt.length(); i++)
        {
            if (txt[i]<a) a=txt[i];
            if (txt[i]>b) b=txt[i];
        }
        cout << int(b-a) << "\n";
    }
}
