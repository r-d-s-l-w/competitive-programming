#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int z, i ,j, k, x, y;
    cin >> z;
    while (z--)
    {
        cin >> i >> j >> k;
        vector <bool> relation(i, false);
        vector <int> osoby;
        relation[k]=true; osoby.push_back(k);
        while (j--)
        {
            cin >> x >> y;
            if (relation[x]==true&&relation[y]==false) {relation[y]=true; osoby.push_back(y);}
        }
        for (int i=0; i<osoby.size(); i++) cout << osoby[i] << " "; cout << endl;
    }
    return 0;
}
