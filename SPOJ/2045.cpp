#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, A, B, C, D, pole=0, x, y, amax, bmax, cmin, dmin;
    cin >> a >> b >> c >> d >> A >> B >> C >> D;
    amax=max(a,A); bmax=max(b,B); cmin=min(c, C); dmin=min(d,D);
    if (cmin-amax>0&&dmin-bmax>0) pole=(c-a)*(d-b)+(C-A)*(D-B)-(cmin-amax)*(dmin-bmax);
    else pole=(c-a)*(d-b)+(C-A)*(D-B);
    cout << pole;
    return 0;
}
