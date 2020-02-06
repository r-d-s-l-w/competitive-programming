#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int  sx, sy, mx, my, d, n, x, y, xd;
    cin >> n;
    while (n--)
    {
        cin >> sx >> sy >> mx >> my >> d;
        x=mx-sx; y=my-sy;
        char tab[d];
        for (int i=0; i<d; i++) cin >> tab[i];
        xd=0;
        while (x!=0||y!=0)
        {
            if (x>0) {if (tab[xd]=='E') x--;}
            else if (x<0) {if (tab[xd]=='W') x++;}
            if (y>0) {if (tab[xd]=='N') y--;}
            else if (y<0) {if (tab[xd]=='S') y++;}
            xd++;
            if (xd==d) break;
        }
        if (x==0&&y==0) cout << xd << endl;
        else cout << "NIE\n";

    }
}
