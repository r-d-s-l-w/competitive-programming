#include <bits/stdc++.h>

using namespace std;

int suma (string nr)
{
    int x = 0;
    for (int i=0; i<nr.length(); i++) x+=nr[i]-48;
    return x;
}
string roznica (string nr)
{
    for (int i=nr.length() - 1; i>=0; i--){
        if (nr[i]=='0') nr[i]='9';
        else
        {
            nr[i]--;
            return nr;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, xd, length, xxd=0; string lol, nr;
    cin >> t;
    while (t--)
    {
        cin >> nr;
        length = nr.length() - 1;
        while (true)
        {
            xd = suma(nr);
            if (xd % 3 == 0 && (nr[length] == '0' || nr[length] == '5')) break;
            nr = roznica(nr);
        }
        if (xd == 0) cout << 0 << endl;
        else {
            for (int i=0; i<length; i++) if (nr[i]!='0') {xxd=i; break;}
            lol = nr.substr(xxd, length-xxd+1);
            cout << lol  << endl;
        }
    }
    return 0;
}
