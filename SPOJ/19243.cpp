#include <iostream>

using namespace std;

unsigned long long int NWD (unsigned long long int a, unsigned long long int b)
{
    if(b) return NWD(b, a%b);
    else return a;
}
unsigned long long int NWW (unsigned long long int a, unsigned long long int b)
{
    return a/NWD(a,b)*b;
}

int main()
{
    unsigned long long int licznik_1, licznik_2, licznik, mianownik_1, mianownik_2, mianownik, xd; char x;
    cin >> licznik_1 >> x >> mianownik_1;
    cin >> licznik_2 >> x >> mianownik_2;
    mianownik=NWW(mianownik_1, mianownik_2);
    licznik=mianownik/mianownik_1*licznik_1+mianownik/mianownik_2*licznik_2;
    xd=NWD(licznik, mianownik);
    licznik/=xd; mianownik/=xd;
    cout << licznik_1 << x << mianownik_1 << " + " << licznik_2 << x << mianownik_2 << " = " << licznik << x << mianownik << endl;

    return 0;
}
