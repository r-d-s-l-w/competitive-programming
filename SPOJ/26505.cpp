#include <iostream>
#include <string>

using namespace std;

bool czyMniejsza (string a, string b)
{
    int x=a[0]*1000+a[1]*100+a[3]*10+a[4], y=b[0]*1000+b[1]*100+b[3]*10+b[4];
    return a<b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n; cin.ignore(); string tab[n], str, mini="99:99";
    for (int i=0; i<n; i++)
        getline(cin, tab[i]);
    for (int i=0; i<n; i++)
    {
        str=tab[i].substr(tab[i].length()-5,5);
        if (czyMniejsza(str, mini)) mini=str;
    }
    for (int i=0; i<n; i++)
    {
        str=tab[i].substr(tab[i].length()-5,5);
        if (str==mini) {tab[i].erase(tab[i].length()-5,5);cout << tab[i] << endl;}
    }

}
