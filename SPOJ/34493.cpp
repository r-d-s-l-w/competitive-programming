#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long long int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    if (a+b==(c+d)*2||a+c==(b+d)*2||a+d==(b+c)*2||(a+b)*2==c+d||(a+c)*2==b+d||(a+d)*2==b+c) cout << 5 << endl;
    else if ((a+b)*2==c+e||(a+c)*2==b+e||(a+e)*2==b+c||a+b==(c+e)*2||a+c==(b+e)*2||a+e==(b+c)*2) cout << 4 << endl;
    else if ((a+b)*2==d+e||(a+d)*2==b+e||(a+e)*2==d+b||a+b==(d+e)*2||a+d==(b+e)*2||a+e==(d+b)*2) cout << 3 << endl;
    else if ((a+c)*2==d+e||(a+d)*2==c+e||(a+e)*2==d+c||a+c==(d+e)*2||a+d==(c+e)*2||a+e==(d+c)*2) cout << 2 << endl;
    else if ((c+b)*2==e+d||(b+d)*2==e+c||(b+e)*2==c+d||c+b==(e+d)*2||b+d==(e+c)*2||b+e==(c+d)*2) cout << 1 << endl;
}
