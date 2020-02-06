#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long long int N, x1, y1, x2, y2, X1, Y1, X2, Y2, x, y, X, Y, a, b, c, temp1, temp2;
    unsigned long long int wynik=1;
    bool hehe;
    cin >> N;
    while (N--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> X1 >> Y1 >> X2 >> Y2;
        if (x1==x2&&y1==y2||X2==X1&&Y1==Y2) cout << "-\n";
        else
        {
            if (x1==X1&&y1==Y1||x2==X1&&y2==Y1||x1==X2&&y1==Y2||x2==X2&&y2==Y2)
            {
                if (x2==X1&&y2==Y1)
                {
                    temp1=x1; temp2=y1;
                    x1=x2; y1=y2;
                    x2=temp1; y2=temp2;
                }
                else if (x1==X2&&y1==Y2)
                {
                    temp1=X1; temp2=Y1;
                    X1=X2; Y1=Y2;
                    X2=temp1; Y2=temp2;
                }
                else if (x2==X2&&y2==Y2)
                {
                    temp1=X1; temp2=Y1;
                    X1=X2; Y1=Y2;
                    X2=temp1; Y2=temp2;
                    temp1=x1; temp2=y1;
                    x1=x2; y1=y2;
                    x2=temp1; y2=temp2;
                }

                x=x2-x1; y=y2-y1; X=y; Y=-x; Y1=y1+Y; X1=x1+X;
                a=y1-Y1;
                b=X1-x1;
                c=(x1-X1)*y1+(Y1-y1)*x1;

                if (x2==X2&&y2==Y2) cout << "-\n";
                else if ((a*x2+b*y2+c)>0&&(a*X2+b*Y2+c)>0||(a*x2+b*y2+c)<0&&(a*X2+b*Y2+c)<0) {cout << "V\n"; wynik*=5;}
                //else if ((a*x2+b*y2+c)*(a*X2+b*Y2+c)>0&&(x1*y2+y1*X2+x2*Y2)-(X2*y2+Y2*x1+x2*y1)!=0) {cout << "V\n"; wynik*=5;}
                else if ((a*x2+b*y2+c)==0||(a*X2+b*Y2+c)==0) {cout << "L\n"; wynik*=50;}
                else cout << "-\n";
            }
            else
            {
                hehe=true;
                a=y1-y2;
                b=x2-x1;
                c=(x1-x2)*y1+(y2-y1)*x1;
                if (((a*X1+b*Y1+c)<0&&(a*X2+b*Y2+c)<0)||((a*X1+b*Y1+c)>0&&(a*X2+b*Y2+c)>0)||((a*X1+b*Y1+c)==0)||((a*X2+b*Y2+c)==0)) hehe=false;
                a=Y1-Y2;
                b=X2-X1;
                c=(X1-X2)*Y1+(Y2-Y1)*X1;
                if (((a*x1+b*y1+c)>0&&(a*x2+b*y2+c)>0)||((a*x1+b*y1+c)<0&&(a*x2+b*y2+c)<0)||((a*x1+b*y1+c)==0)||((a*x2+b*y2+c)==0)) hehe=false;
                if (hehe==true) {cout << "X\n"; wynik*=10;}
                else cout << "-\n";
            }
        }
    }
    cout << wynik;
}
