#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long long int t, x[50000], y[50000], n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=0; i<n; i++)
        {
            cin >> x[i] >> y[i];
        }
        if(n<3) cout << "TAK\n";
        else
        {
            bool xd=true;
            long long int x1, x2, y1, y2, j=1, X, Y;
            x1=x[0];
            y1=y[0];
            while (j<n)
            {
                if (x[j]!=x1||y[j]!=y1)
                {
                    x2=x[j];
                    y2=y[j];
                    break;
                }
                j++;
            }
            X=x2-x1;
            Y=y2-y1;
            for (int i=j+1; i<n; i++)
            {
                if ((y[i]-y1)*X-(Y*(x[i]-x1))!=0)
                {
                    cout << "NIE\n";
                    xd=false;
                    break;
                }
            }
            if (xd==true) cout << "TAK\n";
        }
    }
}
