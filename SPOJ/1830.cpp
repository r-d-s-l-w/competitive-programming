#include <iostream>
using namespace std;

int main()
{
    double a,b,c;
    while (cin>>a>>b>>c)
    {
        if(a+b<=c||a+c<=b||b+c<=a) cout << "0" << endl;
        else cout << "1" << endl;
    }
    return 0;
}
