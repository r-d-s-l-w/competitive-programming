#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; long int x, y;
    vector <long int> tab;
    cin >> n;
    while(n--)
    {
        cin>>x;
        tab.push_back(x);
    }
    char znak;
    cin >> znak >> y;
    if (znak=='<') {for (int i=0;i<tab.size();i++) {if(tab[i]<y) cout << tab[i] << endl;}}
    else for (int i=0;i<tab.size();i++) {if(tab[i]>y) cout << tab[i] << endl;}
    return 0;
}
