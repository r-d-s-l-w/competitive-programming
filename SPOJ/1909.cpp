#include <iostream>
using namespace std;

int main()
{
    long long int x, y=0, suma=0;
    while(cin>>x)
    {
        if (x!=0) y+=x;
        else {cout << y << endl; suma+=y; y=0;}
    }
    cout << suma << endl;
    return 0;
}
