#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    double a, b, x;
    int d;
    cin >> d;
    while (d--)
    {
        x=100;
        cin >> a >> b;
        x-=a/100*x;
        x-=b/100*x;
        x=100-x;
        cout << fixed << setprecision(2) << x << endl;
    }
}
