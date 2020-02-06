#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, x, length, y; char tab[278000];
    cin >> t;
    while (t--)
    {
        cin >> x; length=1;
        for (int i=1; i<x; i++) length*=3;
        for (int i=0; i<length; i++) tab[i]='_'; y=length;
        for (int i=0; i<length; i++) cout << tab[i]; cout << "\n";
        while (true)
        {
            x--; y/=3; if (y==0) break;
            for (int i=0; i<length; i+=y)
                if (tab[i]=='_') for (int j=y; j<2*y; j++) tab[i+j]=' ';
            for (int i=0; i<length; i++) cout << tab[i]; cout << "\n";
        }
        cout << "\n";
    }
}
