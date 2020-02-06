#include <iostream>
using namespace std;

int tab[1003][2];

int main() {
    int d, h;

    cin >> d >> h;

    for(int i = 1; i <= h; i++) cin >> tab[i][0] >> tab[i][1];
    h++;
    tab[h][0] = d;
    tab[h][1] = 0;

    for(int i = 1; i <= h; i++)
    {
        unsigned int mini = 1000000;
        for(int j=i-1; j>=0&&tab[i][0]-tab[j][0]<=800; j--)
            if(mini>tab[i][1]+tab[j][1]) mini=tab[i][1]+tab[j][1];
        tab[i][1] = mini;
    }
    cout << tab[h][1] << endl;
}
