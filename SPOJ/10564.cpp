#include <bits/stdc++.h>

using namespace std;

struct plik
{
    int nr;
    int p;
    int q;
    int r;
};
struct wyjscie
{
    int nr;
    int q;
    int r;
};

bool sortuj (plik i, plik j)
{
    return (i.p<j.p);
}
bool sortuj2 (wyjscie i, wyjscie j)
{
    return (i.q*j.r>j.q*i.r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    plik p; wyjscie x;
    int n, m, h=1, time=0;
    vector <plik> tab;
    vector <wyjscie> arr;
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        cin >> p.nr >> p.p >> p.q >> p.r;
        tab.push_back(p);
    }
    sort(tab.begin(), tab.end(), sortuj);
    p.nr=0; p.p=0; p.q=0; p.r=0; tab.push_back(p);
    for (int i=0; i<n+1; i++)
    {
        if (tab[i].p==h) {x.nr=tab[i].nr; x.q=tab[i].q; x.r=tab[i].r; arr.push_back(x);}
        else
        {
            int xoxo=0, czas=0;
            for (int j=0; j<arr.size(); j++) xoxo+=arr[j].q;
            sort(arr.begin(), arr.end(), sortuj2);
            for (int j=0; j<arr.size(); j++)
            {
                czas=(arr[j].r*xoxo)/(m*arr[j].q);
                time+=czas;
                for (int k=j; k<arr.size(); k++)
                {
                    arr[k].r-=(czas*m*arr[k].q)/xoxo;
                }
                xoxo-=arr[j].q;
                cout << arr[j].nr << " " << time << "\n";
            }
            arr.clear();
            h++;
            x.nr=tab[i].nr; x.q=tab[i].q; x.r=tab[i].r; arr.push_back(x);
        }
    }
}
