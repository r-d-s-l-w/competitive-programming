#include <iostream>

using namespace std;
int t, n, a, suma;
int main()
{
    cin >> t;
    for (int i = 0; i<t; i++)
    {
        suma = 0;
        cin >> n;
        for (int j = 0; j<n; j++)
            {
            cin >> a;
            suma+=a;
            }
        cout << suma << endl;
    }
    return 0;
}
