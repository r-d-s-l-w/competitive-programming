#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int d; unsigned long long int obw, x, y;
    cin >> d;
    while (d--)
    {
        cin >> obw;
        if (obw<4||obw%2==1) cout << "BRAK\n";
        else {
            if (obw%4==0) cout << obw/4*obw/4 << endl;
            else {x=obw/4; y=x+1; cout << x*y << endl;}
        }
    }
}
