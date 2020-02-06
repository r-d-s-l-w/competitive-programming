#include <iostream>
using namespace std;

int main()
{
    unsigned long long int x, tab[65];
    while (cin >> x)
    {
        unsigned long long int i=0, tab[65],  y=0, n=1;
        while (x) {tab[i++]=x%2; x/=2;}
        for(int j=i-1;j>=0;j--)
        {
            y+=tab[j]*n;
            n*=2;
        }
        cout << y << endl;
    }
    return 0;
}
