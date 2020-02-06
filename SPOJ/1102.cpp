#include <iostream>
using namespace std;

int main()
{
    int t,n,k;
    cin >> t;
    while (t--)
    {
        cin>>k;
        double srednia, minimum=101, suma=0; int n[k], xd;
        for (int i=0; i<k; i++)
        {
            cin>> n[i];
            suma+=n[i];
        }
        srednia=suma/k;
        for (int i=k-1; i>=0; i--)
        {
            if ((srednia-n[i])*(srednia-n[i])<=minimum) {minimum=(srednia-n[i])*(srednia-n[i]); xd=i;}
        }
        cout << n[xd] << endl;
    }
    return 0;
}
