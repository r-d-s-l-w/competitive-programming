#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string x; int n, nr, xd, l;
    cin >> n;
    while (n--)
    {
        nr=0; xd=0;
        cin >> x;
        l=x.length();
        if (x[l-1]!='0') cout << "Nie" << endl;
        else
        {
            for (int i=l-2; i>=0; i--)
            {
                if (x[i]=='1')
                {
                    if (xd==0) nr+=2;
                    else if (xd==1) nr+=4;
                    else if (xd==2) nr+=8;
                    else if (xd==3) nr+=6;
                }
                xd++;
                if (xd==4) xd=0;
            }
            if (nr%10==0) cout << "Tak" << endl;
            else cout << "Nie" << endl;
        }
    }
    return 0;
}
