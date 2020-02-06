#include <iostream>
using namespace std;

long long int RED_SQUARE_COUNTER (long long int x, long long int y)
{
    if (y>x) {int z=y; y=x; x=z;}
        long long int k=y/2, suma=0;
        for (int i=k; i>0; i--)
            suma+=4*i-1;
        if ((x-y)%2==0) suma+=y*(x-y)/2;
        else if ((x-y)%2==1&&y%2==0) suma+=y*(x-y-1)/2;
        else suma+=y*(x-y+1)/2;
        return suma;
}

int main()
{
    long long int a, b, x, y, n;
    cin >> a >> b >> x >> y;
    n=RED_SQUARE_COUNTER(x,y)+RED_SQUARE_COUNTER(a,b)-RED_SQUARE_COUNTER(x,b)-RED_SQUARE_COUNTER(a,y);
    cout << n;
    return 0;
}

