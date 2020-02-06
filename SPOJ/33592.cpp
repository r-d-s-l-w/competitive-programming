#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    string a, b; bool xd;
    cin >> t;
    while (t--)
    {
        cin >> a >> b; xd=true;
        if (a.length()!=b.length()) cout << "error\n";
        else
        {
            for (int i=0; i<a.length(); i++)
            {
                if (a[i]!=b[i]&&b[i]!='*') {cout << "error\n"; xd=false; break;}
            }
            if (xd==true) cout << "ok\n";
        }
    }
}
