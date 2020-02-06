#include <iostream>

using namespace std;
int i = 0, j = 0, a, b;
int main()
{
    cin >> a;
    cout << a << endl;
    while (j!=3)
        {
            i++;
            cin >> b;
            if (b == 42 && a != 42) {++j;}
            cout << b << endl;
            a = b;
        }
    return 0;
}
