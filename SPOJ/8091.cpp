#include <bits/stdc++.h>

using namespace std;

bool tab[2500][2500];

int main()
{
    ios_base::sync_with_stdio(0);
    int z;
    cin >> z;
    while (z--)
    {
        int l;
        cin >> l;
        char arr[l]; bool xd=true;
        for (int i=0; i<l; i++) cin >> arr[i];
        int x=1250, y=1250, rozmiar=0, kierunek=0;
        vector <int> X; vector <int> Y; tab[x][y]=true;
        X.push_back(x); Y.push_back(y);
        for (int i=0; i<l; i++)
        {
            if (arr[i]=='R') kierunek+=1;
            else if (arr[i]=='L') kierunek-=1;
            if (kierunek>3) kierunek-=4;
            if (kierunek<0) kierunek+=4;
            if (kierunek==0) y++;
            else if (kierunek==1) x++;
            else if (kierunek==2) y--;
            else x--;
            X.push_back(x); Y.push_back(y);
            if (arr[i]!='E')
            {
                tab[X[rozmiar]][Y[rozmiar]]=false;
                rozmiar++;
            }
            if (tab[x][y]==true)
            {
                cout << i+1 << "\n";
                xd=false;
                break;
            }
            tab[x][y]=true;
        }
        if (xd) cout << "TAK\n";
        for (int i=rozmiar; i<X.size(); i++) tab[X[i]][Y[i]]=false;
    }
}
