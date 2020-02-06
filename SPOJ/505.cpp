#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int d, a, b;
    cin >> d;
    while (d--)
    {

        cin >> a >> b;
        puts((a|b) == a ? "N" : "P");
    }
    return 0;
}
