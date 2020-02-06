#include <iostream>

using namespace std;

int k, p;

int rozklad(int x)
{
    int n=0;
    while (x!=1)
    {
        n++;
        if(x%2==1){x=3*x+1;}
        else {x=x/2;}
    }
    cout << n << endl;
}

int main()
{
    cin >> k;
    for (int i=0; i<k; i++)
    {
        cin >> p;
        rozklad(p);
    }
    return 0;
}
