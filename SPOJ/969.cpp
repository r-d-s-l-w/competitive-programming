#include <iostream>
using namespace std;

int main()
{
    double A, B, C, delta;
    while (cin >> A >> B >> C)
    {
        delta = B*B-4*A*C;
        if (delta<0) cout << "0" << endl;
        else if (delta>0) cout << "2" << endl;
        else if (delta==0) cout << "1" << endl;
    }
    return 0;
}
