#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long long int t, n, p, x, xd;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        x=p; xd=1;
        while (n>x)
        {
            x*=p;
            xd++;
        }
        cout << xd << endl;
    }
}
