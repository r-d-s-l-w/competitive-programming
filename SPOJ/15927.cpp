#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    double t, T, length, v; string x, y;
    while (cin >> x >> y >> length)
    {
        t=((x[0]-'0')*10+(x[1]-'0'))*3600+((x[3]-'0')*10 + (x[4]-'0'))*60+(x[6]-'0')*10 + (x[7]-'0');
        T=((y[0]-'0')*10+(y[1]-'0'))*3600+((y[3]-'0')*10 + (y[4]-'0'))*60+(y[6]-'0')*10 + (y[7]-'0');
        v=length*3.6/(T-t);
        cout << fixed << setprecision(1) << v << " " << v/1.852 << endl;
    }
    return 0;
}
