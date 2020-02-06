#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
    int r, x, y, X, Y, R;
    double dist, c;
    cin >> t;
    while (t--)
    {
        scanf("%d%d%d%d%d%d", &x, &y, &r, &X, &Y, &R);
        c=sqrt((X-x)*(X-x)+(Y-y)*(Y-y));
        dist=r+R-c; if (dist<0) dist=0; else if (R>c+r||r>c+R) dist=2*min(r,R);
        printf("%.2f\n", dist);
    }
    return 0;
}
