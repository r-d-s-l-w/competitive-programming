#include <bits/stdc++.h>

using namespace std;

long long int a (long long int y, long long int Y)
{
    return y-Y;
}
long long int b (long long int x, long long int X)
{
    return X-x;
}
long long int c (long long int x, long long int y, long long int X, long long int Y)
{
    return (x-X)*y+(Y-y)*x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long int x1, x2, x3, y1, y2, y3, x, y;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x >> y)
    {
        if (x1==0&&y1==0&&x2==0&&y2==0&&x3==0&&y3==0&&x==0&&y==0) break;
        else
        {
            if ( (a(y1,y2)*x3 + b(x1,x2)*y3 + c(x1,y1,x2,y2)) * (a(y1,y2)*x + b(x1,x2)*y + c(x1,y1,x2,y2))>0 &&
                 (a(y1,y3)*x2 + b(x1,x3)*y2 + c(x1,y1,x3,y3)) * (a(y1,y3)*x + b(x1,x3)*y + c(x1,y1,x3,y3))>0 &&
                 (a(y2,y3)*x1 + b(x2,x3)*y1 + c(x2,y2,x3,y3)) * (a(y2,y3)*x + b(x2,x3)*y + c(x2,y2,x3,y3))>0 ) cout << "I\n";
            else if ( (a(y1,y2)*x3 + b(x1,x2)*y3 + c(x1,y1,x2,y2)) * (a(y1,y2)*x + b(x1,x2)*y + c(x1,y1,x2,y2))<0 ||
                      (a(y1,y3)*x2 + b(x1,x3)*y2 + c(x1,y1,x3,y3)) * (a(y1,y3)*x + b(x1,x3)*y + c(x1,y1,x3,y3))<0 ||
                      (a(y2,y3)*x1 + b(x2,x3)*y1 + c(x2,y2,x3,y3)) * (a(y2,y3)*x + b(x2,x3)*y + c(x2,y2,x3,y3))<0 ) cout << "O\n";
            else cout << "E\n";
        }
    }
}
