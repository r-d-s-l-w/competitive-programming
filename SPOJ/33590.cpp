#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string liczba; bool xd=false;
    cin >> liczba;
    for (int i=0; i<liczba.length(); i++)
        if (liczba[i]=='0'||liczba[i]=='2'||liczba[i]=='4'||liczba[i]=='6'||liczba[i]=='8') xd=true;
    if (xd==true) cout << "Tak"; else cout << "Nie";
}
