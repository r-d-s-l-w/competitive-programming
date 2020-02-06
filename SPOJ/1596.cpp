#include <iostream>
using namespace std;

int main()
{
    int t,x,y,yy=0;
    cin >> t;
    while (t--)
    {
        cin>>x;
        yy=0;
        for(int i=0; i<x; i++)
        {
            cin>>y;
            yy+=y;
        }
        cout << x+yy-1 << endl;
    }
    return 0;
}
