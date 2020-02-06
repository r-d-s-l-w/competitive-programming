#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int d, w1, w2, w3, p1, p2, p3, w, p;
    cin >> d;
    while (d--)
    {
        cin >> w1 >> p1 >> w2 >> p2 >> w3 >> p3;
        cout << (w1+p1+p1+p2+p3-w1-w2-w3)/2 << " " << (w1+p1-p1-p2-p3+w1+w2+w3)/2 << "\n";
    }
}
