#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long long int k, x=2, y, tab[30], arr[30]; tab[0]=0; arr[0]=1;
    cin >> k;
    for (int i=1; i<30; i++) {arr[i]=x; x*=2; tab[i]=x-2;}
    for (int i=0; i<30; i++) if (k<=tab[i]) {k-=tab[i-1]; y=i-1; break;}
    for (int i=y; i>=0; i--)
    {
        if (k>arr[i]) {cout << '6'; k-=arr[i];}
        else cout << '5';
    }
    return 0;
}
