#include <bits/stdc++.h>
 
using namespace std;
 
struct rect{
    long long x1;
    long long x2;
    long long y1;
    long long y2;
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t, n, m;
    rect b, w;
    cin >> t;
    while (t--){
        long long black = 0, white = 0, x = 0, y = 0, xd = 0;
        cin >> n >> m >> w.x1 >> w.y1 >> w.x2 >> w.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2;
        x = w.x2 - w.x1 + 1;
        y = w.y2 - w.y1 + 1;
        black = (n*m)/2;
        if (n % 2 == 1 && m % 2 == 1)
            white = black + 1;
        else white = black;
 
        xd = (x * y)/2;
        if (x % 2 == 1 && y % 2 == 1)
            if ((w.x1 + w.y1) % 2 == 1)
                xd++;
        black -= xd;
        white += xd;
 
        x = b.x2 - b.x1 + 1;
        y = b.y2 - b.y1 + 1;
        long long amax = max(w.x1, b.x1);
        long long bmax = max(w.y1, b.y1);
        long long amin = min(w.x2, b.x2);
        long long bmin = min(w.y2, b.y2);
        long long A = amin - amax;
        long long B = bmin - bmax;
 
        xd = (x * y)/2;
        if (x % 2 == 1 && y % 2 == 1)
            if ((b.x1 + b.y1) % 2 == 0)
                xd++;
        white -= xd;
        black += xd;
 
        if (A >=0 && B>=0){
            long long X = A + 1;
            long long Y = B + 1;
            xd = (X * Y)/2;
            if (X % 2 == 1 && Y % 2 == 1)
                if ((amax + bmax) % 2 == 1)
                    xd++;
            white -= xd;
            black += xd;
        }
        cout << white << " " << black << "\n";
    }
}
