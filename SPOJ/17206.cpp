#include <iostream>

using namespace std;

int main()
{
    double n;
    while(cin >> n)
    {
        while(n > 9)
            n /= 18.0;
        if (n<=1) cout << "B" << endl;
        else cout << "A" << endl;
    }
    return 0;
}
