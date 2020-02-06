#include <iostream>

using namespace std;

int main()
{
    int t, n, x, xd, tab[4]; tab[0]=6; tab[1]=2; tab[2]=4; tab[3]=8;
    cin >> t;
    while (t--)
    {
        cin >> n; x=1; xd=1;
        while (n!=0)
        {
            while (n%5!=0)
                {x*=n; x%=10; n--;}
            if (n==0) break;
            x*=tab[(n/5)%4]; n/=5;
        }
        cout << x << endl;
    }
}
