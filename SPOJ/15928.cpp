#include <iostream>

using namespace std;

unsigned long long int gcd (unsigned long long int a, unsigned long long int b){
    return b==0?a:gcd(b,a%b);
}
unsigned long long int lcm (unsigned long long int a, unsigned long long int b){
    return a/gcd(a,b)*b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long long int a, b, c, x, y, v1, v2, v3, v4;
    cin >> a >> b >> c;
    v1=lcm(a,b); v2=lcm(a,c); v3=lcm(b,c); v4=lcm(v3, a);
    while (cin >> x >> y)
        cout << y/a+y/b+y/c-y/v1-y/v2-y/v3+y/v4-(x-1)/a-(x-1)/b-(x-1)/c+(x-1)/v1+(x-1)/v2+(x-1)/v3-(x-1)/v4 << endl;

}
