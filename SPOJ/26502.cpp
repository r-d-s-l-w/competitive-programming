#include <iostream>
using namespace std;

int main()
{
    int d, n, x; string day;
    cin >> d;
    while (d--)
    {
        cin >> day >> n;
            if (day=="Pn") x=0;
            else if (day=="Wt") x=1;
            else if (day=="Sr") x=2;
            else if (day=="Cz") x=3;
            else if (day=="Pt") x=4;
            else if (day=="So") x=5;
            else if (day=="Nd") x=6;
        x=(x+n)%7;
        switch (x)
        {
            case 0: cout << "Pn\n"; break;
            case 1: cout << "Wt\n"; break;
            case 2: cout << "Sr\n"; break;
            case 3: cout << "Cz\n"; break;
            case 4: cout << "Pt\n"; break;
            case 5: cout << "So\n"; break;
            case 6: cout << "Nd\n"; break;
        }}
    return 0;
}
