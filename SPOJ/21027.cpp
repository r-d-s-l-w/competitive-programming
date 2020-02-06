#include <iostream>

using namespace std;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long long int a,b,c,s,x,y;
    cin >> a >> b >> c >> s;
    s*=100;
    x=a/gcd(a,b)*b;
    y=x/gcd(x,c)*c;
    cout << s/y;
}
