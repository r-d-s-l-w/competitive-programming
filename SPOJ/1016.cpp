#include <iostream>

using namespace std;

int a, b, t;

int main()
{
    cin>>t;
    for (int i=0; i<t; i++)
    {
        cin >> a >> b;
        cout << (2*a*b)/(a+b) << endl;
    }

    return 0;
}
