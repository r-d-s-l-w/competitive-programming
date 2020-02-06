#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int d, a; string x;
    cin >> d;
    while (d--)
    {
        cin >> a >> x;
        if (x.length()<2) {if (((x[0]-48)+100)%a==0) cout << "TAK\n"; else cout << "NIE\n";}
        else{
        if (((x[x.length()-2]-48)*10+(x[x.length()-1]-48)+100)%a==0) cout << "TAK\n";
        else cout << "NIE\n";}
    }
}
