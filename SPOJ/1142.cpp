#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int D; float X,Y,Z,d;
    cin>>D;
    while(D--)
    {
        cin>>X>>Y>>Z;
        d=((X-Z*Y+Y)/(Z-1))*(-12);
        cout  << round(d) << endl;
    }
    return 0;
}
