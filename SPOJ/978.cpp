#include <iostream>
using namespace std;

int main()
{
    char x; int y, i=0, tab[10];
    while(cin>>x)
    {
        if (x=='+') {if (i<10) {cin >> y; tab[i]=y; i++; cout << ":)" << endl;} else cout << ":(" << endl; }
        if (x=='-') {if (i>0) {i--;cout << tab[i] << endl;} else cout << ":(" << endl;}
    }
    return 0;
}
