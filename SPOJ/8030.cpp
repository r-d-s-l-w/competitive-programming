#include <bits/stdc++.h>

using namespace std;

struct stonoga
{
    long long int x1;
    long long int y1;
    long long int x2;
    long long int y2;
    long long int v;
    long long int A;
    long long int B;
    long long int C;
};

int main()
{
    ios_base::sync_with_stdio(0);
    long long int Z; double x, y; stonoga a, b;
    cin >> Z;
    while (Z--)
    {
        cin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> a.v >> b.x1 >> b.y1 >> b.x2 >> b.y2 >> b.v;
        a.A = a.y1 - a.y2;
        a.B = a.x2 - a.x1;
        a.C = (a.x1 - a.x2) * a.y1 + (a.y2 - a.y1) * a.x1;
        b.A = b.y1 - b.y2;
        b.B = b.x2 - b.x1;
        b.C = (b.x1 - b.x2) * b.y1 + (b.y2 - b.y1) * b.x1;
        if ((a.A * b.B) - (b.A * a.B) == 0) cout << "NIE\n";
        else
        {
            x = ((-a.C * b.B) - (-b.C * a.B)) / ((a.A * b.B) - (b.A * a.B));
            y = ((-b.C * a.A) - (-a.C * b.A)) / ((a.A * b.B) - (b.A * a.B));
            if (x > 100000 || x < -100000 || y > 100000 || y < -100000) cout << "NIE\n";
            else
            {
                double dist_a1 = sqrt ((x - a.x1) * (x - a.x1) + (y - a.y1) * (y - a.y1));
                double dist_a2 = sqrt ((x - a.x2) * (x - a.x2) + (y - a.y2) * (y - a.y2));
                double dist_b1 = sqrt ((x - b.x1) * (x - b.x1) + (y - b.y1) * (y - b.y1));
                double dist_b2 = sqrt ((x - b.x2) * (x - b.x2) + (y - b.y2) * (y - b.y2));
                if (dist_b1 > dist_b2 || dist_a1 > dist_a2) cout << "NIE\n";
                else if ((a.v / dist_a2 <= b.v / dist_b1 && a.v / dist_a1 >= b.v / dist_b1 ) || (b.v / dist_b2 <= a.v / dist_a1 && b.v / dist_b1 >= a.v / dist_a1 )) cout << "TAK\n";
                else cout << "NIE\n";
            }
        }
    }
}
