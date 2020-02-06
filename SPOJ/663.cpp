#include <iostream>

using namespace std;
string tab[1000], key2;
float t, n, d[1000], key, key3, key4;
int x[1000], y[1000];

int main()
{
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> n;
        for(int j=0; j<n; j++)
        {
            cin >> tab[j] >> x[j] >> y[j];
            d[j]=(x[j]*x[j]+y[j]*y[j]);
        }

    for (int i=1; i<n; i++)
        {
            key = d[i];
            key2 = tab[i];
            key3 = x[i];
            key4 = y[i];
            int j=i-1;
            while (j>=0 && d[j]>key)
                {
                    d[j+1]=d[j];
                    x[j+1]=x[j];
                    y[j+1]=y[j];
                    tab[j+1]=tab[j];
                    d[j]=key;
                    x[j]=key3;
                    y[j]=key4;
                    tab[j]=key2;
                    j=j-1;
                }
        }
    for (int i=0; i<n; i++)
    {
        cout << tab[i] << " " << x[i] << " " << y[i] << endl;
    }
    cout << endl;
    }
    return 0;
}
