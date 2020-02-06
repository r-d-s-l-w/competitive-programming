#include <iostream>
using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;
    int x[k], y[k];
    while (n--)
    {
        long long int suma=0;
        for (int i=0; i<k; i++) cin >> x[i];
        for (int i=0; i<k; i++) cin >> y[i];
        for (int i=0; i<k; i++)
        {
            if (y[i]>x[i]) suma+=y[i]-x[i];
            else suma+=x[i]-y[i];
        }
        cout << suma << endl;
    }
    return 0;
}
