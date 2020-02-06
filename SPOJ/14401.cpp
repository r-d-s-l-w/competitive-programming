#include <iostream>

using namespace std;

int gcd (long long int a, long long int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{

    ios_base::sync_with_stdio(0);
    long long int a, b, x, y, c;
    cin >> a >> b;
    c=a/gcd(a,b)*b;
    while (cin >> x >> y)
    {
        cout << (y/b+y/a)-((x-1)/b+(x-1)/a)-(y/c-(x-1)/c) << endl;
    }
}
