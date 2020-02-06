#include <iostream>

using namespace std;

int t, a, b;

int NWD(int a, int b)
{
    if (b==0) {return a;}
    else return NWD(b, a%b);
}

int main()
{
    cin >> t;
    for (int i=0; i<t; i++)
    {
       cin >> a >> b;
       cout << 2*NWD(a, b) << endl;
    }
    return 0;
}
