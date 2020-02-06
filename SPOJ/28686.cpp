#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    double a, b, c, d, A, B, C, D;
    cin >> a >> b >> c >> d >> A >> B >> C >> D;
    cout << "K16K36: " <<  fixed << setprecision(2) << (b*B+d*D)/(B+D) << "\n" << "M16M36: " << (a*A+c*C)/(A+C) << "\n" << "M16K16M36K36: " << (a*A+b*B+c*C+d*D)/(A+B+C+D) << "\n";
}
