#include <iostream>

using namespace std;

int a, b, t, x;
int main()
{
    x=0;
    while (cin >> a)
    {
        x = a + x;
        cout << x << endl;
    }
    return 0;
}
