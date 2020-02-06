#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long double a, b, A, B, X, Y, x, y;
    int k;
    cin >> k;
    while(k--)
    {
        cin >> X >> Y >> x >> y;
        a=max(x, y); b=min(x,y); A=max(X,Y); B=min(X,Y);
        if(a<A&&b<B) cout << "TAK" << endl;
        else if(a>=A&&(a*b)<(A*B)&&((A+B)/(a+b))*((A+B)/(a+b))+((A-B)/(a-b))*((A-B)/(a-b))>2) cout << "TAK" << endl;
        else cout << "NIE" << endl;
    }
    return 0;
}

