#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string tort; long long int x=0, y=0, wynik=0;
    cin >> tort;
    for (int i=0; i<tort.length(); i++) tort[i]=='O'?x++:y++;
    if (x>=y)
    {
        long long int a=0, b=0;
        for (int i=0; i<tort.length(); i++)
        {
            tort[i]=='O'?a++:b++;
            if (a*y==b*x)
            {
                wynik++;
                a=b=0;
            }
        }
        cout << wynik;
    }
    else
    {
        long long int a=0, b=0;
        for (int i=0; i<tort.length(); i++)
        {
            tort[i]=='B'?a++:b++;
            if (a*x==b*y)
            {
                wynik++;
                a=b=0;
            }
        }
        cout << wynik;
    }
}
