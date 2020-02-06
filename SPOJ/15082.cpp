#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long long int P, t, a, b, x;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        P=a*b;
        if (a==1||b==1) cout << (P-2)*(P-1) << endl;
        else cout << 4*(P-4)+(2*((a-2)+(b-2))*(P-6))+(a-2)*(b-2)*(P-9) << endl;
    }
}
