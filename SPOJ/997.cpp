#include <iostream>

using namespace std;

int x, y;
char a;
int main()
{
    while (cin >> a >> x >> y)
    {
       if (a == '+') {cout << x+y << endl;}
       else if (a == '-') {cout << x-y << endl;}
       else if (a == '/') {cout << x/y << endl;}
       else if (a == '*') {cout << x*y << endl;}
       else if (a == '%') {cout << x%y << endl;}
       }

    return 0;
}
