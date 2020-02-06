#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int X, Y, R, n, x, y;
    cin >> X >> Y >> R >> n;
    while (n--)
    {
        cin >> x >> y;
        if (sqrt((x-X)*(x-X)+(y-Y)*(y-Y))>R) cout<< "O" << endl;
        else if (sqrt((x-X)*(x-X)+(y-Y)*(y-Y))==R) cout << "E" << endl;
        else cout << "I" << endl;
    }
    return 0;
}
