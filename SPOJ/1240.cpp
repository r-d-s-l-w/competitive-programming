#include <iostream>

using namespace std;
int t, tab[6], x;
int main()
{
    cin >> t;
    for (int i=0; i<t; i++)
    {
        for(int j=0; j<6; j++)
        {
            cin >> tab[j];
        }
        x = tab[0]*tab[3]+tab[2]*tab[5]+tab[4]*tab[1]-tab[4]*tab[3]-tab[0]*tab[5]-tab[2]*tab[1];
        if (x==0) {cout << "TAK" << endl;}
        else {cout << "NIE" << endl;}
    }
    return 0;
}
