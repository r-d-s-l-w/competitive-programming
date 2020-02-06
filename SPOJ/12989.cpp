#include <iostream>
using namespace std;

int main()
{
    long long int x, y=0, z=0;
    while (cin>>x)
    {
        if (x==0) break;
        if (x>z) {y=z; z=x;}
        else if (x>y&&x<z) y=x;
    }
    if (y!=0) cout << y << endl;
    else cout << z << endl;
    return 0;
}
