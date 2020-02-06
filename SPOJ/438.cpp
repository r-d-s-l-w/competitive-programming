#include <iostream>
#include <cmath>

using namespace std;
int n, x, y;
int main()
{
    y = 10000;
    bool liczby[y+1];

    for(int i=0; i<=y; i++)
    {
        liczby[i] = true;
    }

    liczby[0] = false;
    liczby[1] = false;

    for(int i=2; i<=sqrt(y); i++)
    {
        if (liczby[i] == true)
        {
        for(int j=i+i; j<=y; j+=i)
        {
            liczby[j] = false;
        }
        }
    }

    cin >> n;
    for (int i=0; i<n; i++)
    {
       cin >> x;
       if (liczby[x] == true) {cout << "TAK" << endl;}
       else {cout << "NIE" << endl;}

    }

    return 0;
}
