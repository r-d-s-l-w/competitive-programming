#include <iostream>
using namespace std;

int main()
{
    string a, b, c, d, x, y, z;
    while (cin >> a >> x >> b >> y >> c >> d >> z)
    {
        int X=0,Y=0,Z=0;
        if(x[0]<65||x[0]>90) X=1;
        for (int i=1; i<x.length()-1; i++)
        {
            if (X==1) break;
            if (x[i]>122||x[i]<97) X=1;
            if (i==10) X=1;
        }
        if(y[0]<65||y[0]>90) Y=1;
        for (int i=1; i<y.length()-1; i++)
        {
            if (Y==1) break;
            if (y[i]>122||y[i]<97) Y=1;
            if (i==20) Y=1;
        }
        int y,m,d;
        y=(z[0]-48)*1000+(z[1]-48)*100+(z[2]-48)*10+(z[3]-48);
        m=(z[5]-48)*10+(z[6]-48);
        d=(z[8]-48)*10+(z[9]-48);
        if(y<1900||y>2000||m>12||m<1||d>31||d<1) Z=1;
        if (X==1) cout << "0" << endl;
        else if (Y==1) cout << "1" << endl;
        else if (Z==1) cout << "2" << endl;
        else cout << "3" << endl;
    }
    return 0;
}
