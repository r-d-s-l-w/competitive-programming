#include <iostream>

using namespace std;

int a, b, N, x, y;
int main()
{
    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> a >> b;
        x = b;
        y = a;
        while (a!=b)
        {
            if (a>b) {b = b+x;}
            else {a = a+y;}
        }
        cout << a << endl;
    }
    return 0;
}
