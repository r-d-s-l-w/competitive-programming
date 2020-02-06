#include <bits/stdc++.h>

using namespace std;

struct POINT
{
    long long int x;
    long long int y;
};

long long int polygonArea (vector <POINT> tab)
{
    long long int area = 0;
    int s = tab.size();
    for (int i=0; i<s; i++)
        area += (tab[i].x + tab[(i + 1) % s].x) * (tab[i].y - tab[(i + 1) % s].y);
    return area<0?area*=-1:area;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        POINT a;
        long long int X, Y, x, y;
        long long int area[2];
        vector <POINT> tab;
        for (int i=0; i<2; i++)
        {
            vector <POINT> tab;
            cin >> X >> Y;
            a.x = X;
            a.y = Y;
            tab.push_back(a);
            while (cin >> x >> y)
            {
                if (x==X && y==Y) break;
                else
                {
                    a.x = x;
                    a.y = y;
                    tab.push_back(a);
                }
            }
            area[i] = polygonArea(tab);
            tab.clear();
        }
        if (area[0]>area[1])
        {
            long long int temp = area[0];
            area[0] = area[1];
            area[1] = temp;
        }
        cout << (area[0] * 5) + 3*(area[1] - area[0]) << "\n";
    }
}
