#include <iostream>
using namespace std;

int main()
{
    float a, b, c, wynik, maks, x, y;
    while (cin>>a>>b>>c)
    {

        if (a>b) {maks=a; x=b;} else {maks=b; x=a;} if(maks<c) {y=maks; maks=c;} else y=c;
        if (maks<x+y)
        {
        if (x*x+y*y==maks*maks) cout << "prostokatny" << endl;
        else if (x*x+y*y>maks*maks) cout << "ostrokatny" << endl;
        else cout << "rozwartokatny" << endl;
        }
        else cout << "brak" << endl;

    }
    return 0;
}
