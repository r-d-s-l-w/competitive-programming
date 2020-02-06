#include <bits/stdc++.h>

using namespace std;

int naint (string x)
{
    int a=0, c=1;
    for (int i=x.length()-1; i>=0; i--)
    {
        a+=(x[i]-48)*c;
        c*=10;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n; string x; bool tab[1000001];
    for (int i=0; i<1000001; i++) tab[i]=true;
    tab[1]=false;
    for (int i=2; i<1000; i++) if (tab[i]==true) for (int j=i+i; j<1000001; j+=i) tab[j]=false;
    cin >> n;
    while (n--)
    {
        cin >> x; bool czyPierwsza=true;
        for (int i=0; i<x.length(); i++)
        {
            string y = x.substr(0,x.length()-i);
            if (tab[naint(y)]==false) {czyPierwsza=false; break;}
        }
        czyPierwsza==true?cout<<"TAK\n":cout<<"NIE\n";
    }

}
