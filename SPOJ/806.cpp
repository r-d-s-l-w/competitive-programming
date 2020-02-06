#include <iostream>
#define FOR(x, b, e) for(int x=b; x<(e); ++x)
using namespace std;

int main()
{
    int n, Size, mid;
    while(true)
    {
        cin >> n;
        if (n==0) break; if (n<0) Size=-2*n; else Size=2*n; mid=Size/2;
        char tab[Size][Size];
        FOR(x, 0, Size){FOR(y, 0, Size) tab[x][y]='.';}
        if (n>0){
        FOR(x, 0, mid){FOR(y, 0, mid) if (x<=y) tab[x][y]='*';}
        FOR(x, 0, mid){FOR(y, mid, Size) if (x+1>=Size-y) tab[x][y]='*';}
        FOR(x, mid, Size){FOR(y, 0, mid) if (Size-x>=y+1) tab[x][y]='*';}
        FOR(x, mid, Size){FOR(y, mid, Size) if (x+1>y) tab[x][y]='*';}}
        if (n<0){
        FOR(x, mid, Size){FOR(y, mid, Size) if (x<=y) tab[x][y]='*';}
        FOR(x, mid, Size){FOR(y, 0, mid) if (x+1>=Size-y) tab[x][y]='*';}
        FOR(x, 0, mid){FOR(y, mid, Size) if (Size-x>=y+1) tab[x][y]='*';}
        FOR(x, 0, mid){FOR(y, 0, mid) if (x+1>y) tab[x][y]='*';}}

        FOR(y, 0, Size){FOR(x, 0, Size) cout << tab[x][y]; cout << endl;}
        cout << endl;
    }

    return 0;
}
