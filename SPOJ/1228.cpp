#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a, b,c;
    cin >> a >> b >> c;
    if (a==0){if (b==c) cout << "NWR"; else cout << "BR";}
    else if(((c-b)/a)-int((c-b)/a)!=0) cout << setprecision(4) << (c-b)/a;
    else cout << (c-b)/a <<".00";
    return 0;
}
