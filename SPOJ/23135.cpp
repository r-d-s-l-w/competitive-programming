#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t; double r, c, w, h, x;
    cin >> t;
    while (t--)
    {
        cin >> r >> c >> w >> h;
        x=sqrt(r*r-c*c);
        if (h+w>=x+r) cout << "NIE\n";
        else if (w>=c) cout << "NIE\n";
        else cout << "TAK\n";
    }
}
